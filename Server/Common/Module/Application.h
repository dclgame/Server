#ifndef __DEPENDS_MODULE_APPLICATION_HEADER__
#define __DEPENDS_MODULE_APPLICATION_HEADER__
#include <string>
#include "Module.h"
#include "NFPlatform.h"
using namespace std;
//typedef std::function<bool(const std::string &strFileName, std::string &strContent)> GET_FILECONTENT_FUNCTOR;

#define FIND_MODULE(classBaseName, className)  \
	assert((TIsDerived<classBaseName, NFIModule>::Result));

class Application : public Module
{
public:
	Application()
	{

	}

	template <typename T>
	T* FindModule()
	{
		T* pLogicModule = FindModule(typeid(T).name());
		if (pLogicModule)
		{
// 			if (!TIsDerived<T, NFIModule>::Result)
// 			{
// 				return NULL;
// 			}
			//TODO OSX…œdynamic_cast∑µªÿ¡ÀNULL
#if NF_PLATFORM == NF_PLATFORM_APPLE
			T* pT = (T*)pLogicModule;
#else
			T* pT = dynamic_cast<T*>(pLogicModule);
#endif
			assert(NULL != pT);

			return pT;
		}
		assert(pLogicModule != NULL);
		return NULL;
	}

	virtual void AddModule(const string& strModuleName, Module* pModule) = 0;

	virtual void RemoveModule(const string& strModuleName) = 0;

	virtual Module* FindModule(const string& strModuleName) = 0;

	virtual int GetAppID() const = 0;
	virtual void SetAppID(const int nAppID) = 0;

	virtual const string& GetConfigPath() const = 0;
	virtual void SetConfigName(const string& strFileName) = 0;

	virtual const string& GetAppName() const = 0;
	virtual void SetAppName(const string& strAppName) = 0;

	virtual const string& GetLogConfigName() const = 0;
	virtual void SetLogConfigName(const string& strName) = 0;

	//virtual void SetGetFileContentFunctor(GET_FILECONTENT_FUNCTOR fun) = 0;
	//virtual bool GetFileContent(const std::string &strFileName, std::string &strContent) = 0;
};

#endif
