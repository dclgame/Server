#include "MasterApp.h"

MasterApp::MasterApp()
{

}

MasterApp::~MasterApp()
{

}

MasterApp& MasterApp::getInstance()
{
	static MasterApp instance;
	return instance;
}

bool MasterApp::Awake()
{
	return true;
}

bool MasterApp::Init()
{
	return true;
}

bool MasterApp::AfterInit()
{
	return true;
}

bool MasterApp::CheckConfig()
{
	return true;
}

bool MasterApp::ReadyExecute()
{
	return true;
}

bool MasterApp::Execute()
{
	return true;
}

bool MasterApp::BeforeShut()
{
	return true;
}

bool MasterApp::Shut()
{
	return true;
}

bool MasterApp::Finalize()
{
	return true;
}

bool MasterApp::ReleaseInstance()
{
	return true;
}

void MasterApp::AddModule(const string& strModuleName, Module* pModule)
{

}

void MasterApp::RemoveModule(const string& strModuleName)
{

}

Module* MasterApp::FindModule(const string& strModuleName)
{
	auto it = mModuleMap.find(strModuleName);
	if (it != mModuleMap.end())
	{
		return it->second;
	}
	return NULL;
}

int MasterApp::GetAppID() const
{
	return nAppID;
}

void MasterApp::SetAppID(const int nAppID)
{

}

const string& MasterApp::GetConfigPath() const
{
	return sConfigPath;
}

void MasterApp::SetConfigName(const string& strFileName)
{

}

const string& MasterApp::GetAppName() const
{
	return sConfigName;
}

void MasterApp::SetAppName(const string& strAppName)
{

}

const string& MasterApp::GetLogConfigName() const
{
	return sLogConfigName;
}

void MasterApp::SetLogConfigName(const string& strName)
{

}

