#ifndef H_NETWORK_H
#define H_NETWORK_H

#include "Net.h"

#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/thread.h>
#include <event2/event_compat.h>

#pragma pack(push, 1)

class Network : public Net
{
public:
	Network()
    {
        base = NULL;
        listener = NULL;

        mstrIP = "";
        mnPort = 0;
        mnCpuCount = 0;
        mbServer = false;
        mbWorking = false;

        mnSendMsgTotal = 0;
        mnReceiveMsgTotal = 0;

		mnBufferSize = 0;
    }

    template<typename BaseType>
	Network(BaseType* pBaseType, void (BaseType::*handleRecieve)(const SOCKID, const int, const char*, const uint32_t), void (BaseType::*handleEvent)(const SOCKID, const NET_EVENT, Net*))
    {
        base = NULL;
        listener = NULL;

        mRecvCB = std::bind(handleRecieve, pBaseType, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
        mEventCB = std::bind(handleEvent, pBaseType, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
        mstrIP = "";
        mnPort = 0;
        mnCpuCount = 0;
        mbServer = false;
        mbWorking = false;
        
        mnSendMsgTotal = 0;
        mnReceiveMsgTotal = 0;

		mnBufferSize = 0;
    }
	virtual ~Network() {};

public:
    virtual bool Execute();

    virtual void Initialization(const char* strIP, const unsigned short nPort);
    virtual int Initialization(const unsigned int nMaxClient, const unsigned short nPort, const int nCpuCount = 4);
	virtual int ExpandBufferSize(const unsigned int size);

    virtual bool Final();

    
    virtual bool SendMsgWithOutHead(const int16_t nMsgID, const char* msg, const uint32_t nLen, const SOCKID nSockIndex);

    
    virtual bool SendMsgWithOutHead(const int16_t nMsgID, const char* msg, const uint32_t nLen, const std::list<SOCKID>& fdList);

    
    virtual bool SendMsgToAllClientWithOutHead(const int16_t nMsgID, const char* msg, const uint32_t nLen);


    virtual bool CloseNetObject(const SOCKID nSockIndex);
	virtual bool AddNetObject(const SOCKID nSockIndex, NetObject* pObject);
	virtual NetObject* GetNetObject(const SOCKID nSockIndex);

    virtual bool IsServer();
    virtual bool Log(int severity, const char* msg);

private:
    
    bool SendMsgToAllClient(const char* msg, const uint32_t nLen);

    
	bool SendMsg(const char* msg, const uint32_t nLen, const std::list<SOCKID>& fdList);
	bool SendMsg(const char* msg, const uint32_t nLen, const SOCKID nSockIndex);

	//inline bool SendMsgToAllClient(const char* msg, const size_t nLen) { return SendMsgToAllClient(msg, (uint32_t)nLen); }
	//inline bool SendMsg(const char* msg, const size_t nLen, const std::list<SOCKID>& fdList) { return SendMsg(msg, (uint32_t)nLen, fdList); }
	//inline bool SendMsg(const char* msg, const size_t nLen, const SOCKID nSockIndex) { return SendMsg(msg, (uint32_t)nLen, nSockIndex); }


private:
    void ExecuteClose();
    bool CloseSocketAll();

    bool Dismantle(NetObject* pObject);


    int InitClientNet();
    int InitServerNet();
	void CloseObject(const SOCKID nSockIndex);

    static void listener_cb(struct evconnlistener* listener, evutil_socket_t fd, struct sockaddr* sa, int socklen, void* user_data);
    static void conn_readcb(struct bufferevent* bev, void* user_data);
    static void conn_writecb(struct bufferevent* bev, void* user_data);
    static void conn_eventcb(struct bufferevent* bev, short events, void* user_data);
    static void log_cb(int severity, const char* msg);

protected:
    int DeCode(const char* strData, const uint32_t unLen, MsgHead& xHead);
    int EnCode(const uint16_t unMsgID, const char* strData, const uint32_t unDataLen, std::string& strOutData);

private:
    //<fd,object>


	std::map<SOCKID, NetObject*> mmObject;
	std::vector<SOCKID> mvRemoveObject;

    int mnMaxConnect;
    std::string mstrIP;
    int mnPort;
    int mnCpuCount;
	bool mbServer;

	int mnBufferSize;

    bool mbWorking;

    int64_t mnSendMsgTotal;
    int64_t mnReceiveMsgTotal;

    struct event_base* base;
    struct evconnlistener* listener;
    //////////////////////////////////////////////////////////////////////////

    NET_RECEIVE_FUNCTOR mRecvCB;
    NET_EVENT_FUNCTOR mEventCB;

    //////////////////////////////////////////////////////////////////////////
};

#pragma pack(pop)

#endif
