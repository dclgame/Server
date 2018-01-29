#ifndef H_APPLICATION_H
#define H_APPLICATION_H
#include <string>
#include "Module.h"
#include "Define.h"
using namespace std;

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
			T* pT = dynamic_cast<T*>(pLogicModule);
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
};

#endif
