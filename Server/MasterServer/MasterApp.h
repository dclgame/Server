#ifndef H_MASTER_APP_H
#define H_MASTER_APP_H
#include "Application.h"
#include "HtString.h"
#include <unordered_map>

typedef unordered_map<string, Module*> ModuleMap;

class MasterApp :Application
{
private:
	MasterApp();

public:
	virtual ~MasterApp();
	static MasterApp& getInstance();

	virtual bool Awake();

	virtual bool Init();

	virtual bool AfterInit();

	virtual bool CheckConfig();

	virtual bool ReadyExecute();
 
	virtual bool Execute();


	virtual bool BeforeShut();

	virtual bool Shut();

	virtual bool Finalize();

	virtual bool ReleaseInstance();

	 



	/////////////////////////////////////////////////////
	virtual void AddModule(const string& strModuleName, Module* pModule);
	virtual void RemoveModule(const string& strModuleName);

	virtual Module* FindModule(const string& strModuleName);
	virtual int GetAppID() const;
	virtual void SetAppID(const int nAppID);
	virtual const string& GetConfigPath() const;
	virtual void SetConfigName(const string& strFileName);
	virtual const string& GetAppName() const;
	virtual void SetAppName(const string& strAppName);
	virtual const string& GetLogConfigName() const;
	virtual void SetLogConfigName(const string& strName);

private:
	int nAppID;
	string sConfigPath;
	string sConfigName;
	string sLogConfigName;

	ModuleMap mModuleMap;

};

#endif



