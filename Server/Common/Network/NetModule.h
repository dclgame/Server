#ifndef H_NET_Module_H
#define H_NET_Module_H

#include <iostream>
#include <iosfwd>
#include "Net.h"
#include "NetModuleBase.h"
// #include "NFComm/NFCore/NFQueue.hpp"
// #include "NFComm/NFPluginModule/NFINetModule.h"
// #include "NFComm/NFPluginModule/NFIPluginManager.h"
// #include "NFComm/NFMessageDefine/MsgDefine.h"
#ifdef _MSC_VER
#pragma warning(disable: 4244 4267)
#endif
//#include "NFComm/NFMessageDefine/NFDefine.pb.h"
#ifdef _MSC_VER
#pragma warning(default: 4244 4267)
#endif

class NetModule
	: public NetModuleBase
{
public:
	//NetModule(NFIPluginManager* p);

	virtual ~NetModule();

	//as client
	virtual void Initialization(const char* strIP, const unsigned short nPort);

	//as server
	virtual int Initialization(const unsigned int nMaxClient, const unsigned short nPort, const int nCpuCount = 4);
	virtual int ExpandBufferSize(const unsigned int size = 1024 * 1024 * 20);

	virtual void RemoveReceiveCallBack(const int nMsgID);

	virtual bool AddReceiveCallBack(const int nMsgID, const NET_RECEIVE_FUNCTOR_PTR& cb);

	virtual bool AddReceiveCallBack(const NET_RECEIVE_FUNCTOR_PTR& cb);

	virtual bool AddEventCallBack(const NET_EVENT_FUNCTOR_PTR& cb);

	virtual bool Execute();


	virtual bool SendMsgWithOutHead(const int nMsgID, const std::string& msg, const SOCKID nSockIndex);

	virtual bool SendMsgToAllClientWithOutHead(const int nMsgID, const std::string& msg);

	virtual bool SendMsg(const uint16_t nMsgID, const google::protobuf::Message& xData, const SOCKID nSockIndex);

	virtual bool SendMsg2AllClient(const uint16_t nMsgID, const google::protobuf::Message& xData);

	virtual bool SendMsg(const uint16_t nMsgID, const google::protobuf::Message& xData, const SOCKID nSockIndex, const module::GUID nPlayer, const std::vector<module::GUID>* pClientIDList = NULL);

	virtual bool SendMsg(const uint16_t nMsgID, const std::string& strData, const SOCKID nSockIndex, const module::GUID nPlayer, const std::vector<module::GUID>* pClientIDList = NULL);

	virtual Net* GetNet();

protected:
	void OnReceiveNetPack(const SOCKID nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);

	void OnSocketNetEvent(const SOCKID nSockIndex, const NET_EVENT eEvent, Net* pNet);

	void KeepAlive();

private:

	int mnBufferSize;
	Net* m_pNet;
	INT64 nLastTime;
	std::map<int, NET_RECEIVE_FUNCTOR_PTR> mxReceiveCallBack;
	std::list<NET_EVENT_FUNCTOR_PTR> mxEventCallBackList;
	std::list<NET_RECEIVE_FUNCTOR_PTR> mxCallBackList;
};
#endif