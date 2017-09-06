#include <time.h>
#include <stdio.h>
#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <future>
#include <functional>
#include <atomic>
#include "NFPlatform.h"
#if NF_PLATFORM == NF_PLATFORM_LINUX
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/prctl.h>
#endif
#include "MasterApp.h"
using namespace std;
bool bExitApp = false;
std::thread gThread;
std::string strArgvList;
std::string strConfigName;
std::string sAppName;
std::string sAppID;
std::string strTitleName;

#if NF_PLATFORM == NF_PLATFORM_WIN
//获取调用堆栈
#pragma comment( lib, "DbgHelp" )

void CreateDumpFile(const std::string& strDumpFilePathName, EXCEPTION_POINTERS* pException)
{
	//Dump
	HANDLE hDumpFile = CreateFile(strDumpFilePathName.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	MINIDUMP_EXCEPTION_INFORMATION dumpInfo;
	dumpInfo.ExceptionPointers = pException;
	dumpInfo.ThreadId = GetCurrentThreadId();
	dumpInfo.ClientPointers = TRUE;

	MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hDumpFile, MiniDumpNormal, &dumpInfo, NULL, NULL);

	CloseHandle(hDumpFile);
}

//
long ApplicationCrashHandler(EXCEPTION_POINTERS* pException)
{
	time_t t = time(0);
	char szDmupName[MAX_PATH];
	tm* ptm = localtime(&t);

	sprintf_s(szDmupName, "%04d_%02d_%02d_%02d_%02d_%02d.dmp", ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
	CreateDumpFile(szDmupName, pException);

	FatalAppExit(-1, szDmupName);

	return EXCEPTION_EXECUTE_HANDLER;
}
#endif

void CloseXButton()
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	HWND hWnd = GetConsoleWindow();
	if (hWnd)
	{
		HMENU hMenu = GetSystemMenu(hWnd, FALSE);
		EnableMenuItem(hMenu, SC_CLOSE, MF_DISABLED | MF_BYCOMMAND);
	}
#endif
}

void ThreadFunc()
{
	while (!bExitApp)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		std::string s;
		std::cin >> s;
		if (0 == stricmp(s.c_str(), "exit"))
		{
			bExitApp = true;
			gThread.detach();
		}
	}
}

void CreateBackThread()
{
	gThread = std::thread(std::bind(&ThreadFunc));
	auto f = std::async(std::launch::deferred, std::bind(ThreadFunc));
	std::cout << "CreateBackThread, thread ID = " << gThread.get_id() << std::endl;
}

void InitDaemon()
{
#if NF_PLATFORM == NF_PLATFORM_LINUX
	daemon(1, 0);
	// ignore signals
	signal(SIGINT, SIG_IGN);
	signal(SIGHUP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
#endif
}


void ProcessParameter(int argc, char* argv[])
{
	string sAppNameTitle = "Server";
	string sAppIdTitle = "ID";
	for (int i = 1; i < argc; i++ )
	{
		string sArg = argv[i];

		if (sArg.find(sAppNameTitle) != string::npos)
		{
			sAppName = HtString::GetParmStr(sArg, "=", sAppNameTitle);
			MasterApp::getInstance().SetAppName(sAppName);
			continue;
		}

		if (sArg.find(sAppIdTitle) != string::npos)
		{
			sAppID = HtString::GetParmStr(sArg, "=", sAppIdTitle);
			MasterApp::getInstance().SetAppID(HtString::StrConvertToInt(sAppID));
			continue;
		}
	}	
	strTitleName = sAppName + sAppID; //+" PID" + NFGetPID();
#if NF_PLATFORM == NF_PLATFORM_WIN
	SetConsoleTitle(strTitleName.c_str());
#elif NF_PLATFORM == NF_PLATFORM_LINUX
	prctl(PR_SET_NAME, strTitleName.c_str());
#endif
}

int main(int argc, char* argv[])
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	//异常处理
	SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)ApplicationCrashHandler);
#elif NF_PLATFORM == NF_PLATFORM_LINUX
	InitDaemon();
}
#endif

	ProcessParameter(argc, argv);

	CreateBackThread();

	MasterApp::getInstance().Awake();
	MasterApp::getInstance().Init();
	MasterApp::getInstance().AfterInit();
	MasterApp::getInstance().CheckConfig();
	MasterApp::getInstance().ReadyExecute();


	uint64_t nIndex = 0;
	while (!bExitApp)
	{
		while (true)
		{
			nIndex++;

			std::this_thread::sleep_for(std::chrono::milliseconds(1));

			if (bExitApp)
			{
				break;
			}

#if NF_PLATFORM == NF_PLATFORM_WIN
			__try
			{
#endif
				MasterApp::getInstance().Execute();
#if NF_PLATFORM == NF_PLATFORM_WIN
			}
			__except (ApplicationCrashHandler(GetExceptionInformation()))
			{
			}
#endif
		}
	}
	MasterApp::getInstance().BeforeShut();
	MasterApp::getInstance().Shut();
	MasterApp::getInstance().Finalize(); 
	MasterApp::getInstance().ReleaseInstance();

	return 0;
}
