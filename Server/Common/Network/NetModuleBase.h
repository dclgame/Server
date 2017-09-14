#ifndef H_NET_MODULEBASE_H
#define H_NET_MODULEBASE_H

#include <iostream>
#include <iosfwd>
#include "GUID.h"
#include "Module.h"
#include "Net.h"
#include "MsgDefine.pb.h"
#include "MsgDefine.pb.cc"
#ifdef _MSC_VER
#pragma warning(disable: 4244 4267)
#endif
#ifdef _MSC_VER
#pragma warning(default: 4244 4267)
#endif

enum SERVER_TYPES
{
	ST_NONE = 0,    // NONE
	ST_REDIS = 1,    //
	ST_MYSQL = 2,    //
	ST_MASTER = 3,    //
	ST_LOGIN = 4,    //
	ST_PROXY = 5,    //
    ST_GAME = 6,    //
	ST_WORLD = 7,    //
	ST_AI = 8,	//
	ST_MAX = 9,    //

};

struct ServerData
{
	ServerData()
	{
		pData = SHARE_PTR<Msg::ServerInfoReport>(NEW Msg::ServerInfoReport());
		nFD = 0;
	}
	~ServerData()
	{
		nFD = 0;
		pData = NULL;
	}

	SOCKID nFD;
	SHARE_PTR<Msg::ServerInfoReport> pData;
};

class NetModuleBase
	: public Module
{
public:
	static GUID PBToGUid(Msg::Ident xID)
	{
		GUID  xIdent;
		xIdent.nHead64 = xID.svrid();
		xIdent.nData64 = xID.index();

		return xIdent;
	}

	static Vector2 PBToNF(Msg::Vector2 value)
	{
		Vector2  vector;
		vector.SetX(value.x());
		vector.SetY(value.y());
		return vector;
	}

	static Vector3 PBToNF(Msg::Vector3 value)
	{
		Vector3  vector;
		vector.SetX(value.x());
		vector.SetY(value.y());
		vector.SetZ(value.z());
		return vector;
	}

	static NFMsg::Ident NFToPB(GUID xID)
	{
		NFMsg::Ident  xIdent;
		xIdent.set_svrid(xID.nHead64);
		xIdent.set_index(xID.nData64);

		return xIdent;
	}

	static NFMsg::Vector2 NFToPB(Vector2 value)
	{
		NFMsg::Vector2  vector;
		vector.set_x(value.X());
		vector.set_y(value.Y());
		return vector;
	}

	static NFMsg::Vector3 NFToPB(Vector3 value)
	{
		NFMsg::Vector3  vector;
		vector.set_x(value.X());
		vector.set_y(value.Y());
		vector.set_z(value.Z());
		return vector;
	}

	template<typename BaseType>
	bool AddReceiveCallBack(const int nMsgID, BaseType* pBase, void (BaseType::*handleRecieve)(const SOCKID, const int, const char*, const uint32_t))
	{
		NET_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
		NET_RECEIVE_FUNCTOR_PTR functorPtr(new NET_RECEIVE_FUNCTOR(functor));

		return AddReceiveCallBack(nMsgID, functorPtr);
	}

	template<typename BaseType>
	bool AddReceiveCallBack(BaseType* pBase, void (BaseType::*handleRecieve)(const SOCKID, const int, const char*, const uint32_t))
	{
		NET_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
		NET_RECEIVE_FUNCTOR_PTR functorPtr(new NET_RECEIVE_FUNCTOR(functor));

		return AddReceiveCallBack(functorPtr);
	}

	template<typename BaseType>
	bool AddEventCallBack(BaseType* pBase, void (BaseType::*handler)(const SOCKID, const NF_NET_EVENT, NFINet*))
	{
		NET_EVENT_FUNCTOR functor = std::bind(handler, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
		NET_EVENT_FUNCTOR_PTR functorPtr(new NET_EVENT_FUNCTOR(functor));

		return AddEventCallBack(functorPtr);
	}

	static bool ReceivePB(const int nMsgID, const char * msg, const uint32_t nLen, std::string & strMsg, GUID & nPlayer)
	{
		Msg::MsgBase xMsg;
		if (!xMsg.ParseFromArray(msg, nLen))
		{
			char szData[MAX_PATH] = { 0 };
			NFSPRINTF(szData, MAX_PATH, "Parse Message Failed from Packet to MsgBase, MessageID: %d\n", nMsgID);
			//LogRecive(szData);

			return false;
		}

		strMsg.assign(xMsg.msg_data().data(), xMsg.msg_data().length());

		nPlayer = PBToNF(xMsg.player_id());

		return true;
	}

	static bool ReceivePB(const int nMsgID, const std::string& strMsgData, google::protobuf::Message & xData, GUID & nPlayer)
	{
		return ReceivePB(nMsgID, strMsgData.c_str(), (uint32_t)strMsgData.length(), xData, nPlayer);
	}

	static bool ReceivePB(const int nMsgID, const char * msg, const uint32_t nLen, google::protobuf::Message & xData, GUID & nPlayer)
	{
		Msg::MsgBase xMsg;
		if (!xMsg.ParseFromArray(msg, nLen))
		{
			char szData[MAX_PATH] = { 0 };
			NFSPRINTF(szData, MAX_PATH, "Parse Message Failed from Packet to MsgBase, MessageID: %d\n", nMsgID);
			//LogRecive(szData);

			return false;
		}

		if (!xData.ParseFromString(xMsg.msg_data()))
		{
			char szData[MAX_PATH] = { 0 };
			NFSPRINTF(szData, MAX_PATH, "Parse Message Failed from MsgData to ProtocolData, MessageID: %d\n", nMsgID);
			//LogRecive(szData);

			return false;
		}

		nPlayer = PBToNF(xMsg.player_id());

		return true;
	}

	/////////////////
	//as client
	virtual void Initialization(const char* strIP, const unsigned short nPort) = 0;

	//as server
	virtual int Initialization(const unsigned int nMaxClient, const unsigned short nPort, const int nCpuCount = 4) = 0;
	virtual int ExpandBufferSize(const unsigned int size = 1024 * 1024 * 20) = 0;

	virtual void RemoveReceiveCallBack(const int nMsgID) = 0;

	virtual bool AddReceiveCallBack(const int nMsgID, const NET_RECEIVE_FUNCTOR_PTR& cb) = 0;

	virtual bool AddReceiveCallBack(const NET_RECEIVE_FUNCTOR_PTR& cb) = 0;

	virtual bool AddEventCallBack(const NET_EVENT_FUNCTOR_PTR& cb) = 0;

	virtual bool Execute() = 0;


	virtual bool SendMsgWithOutHead(const int nMsgID, const std::string& msg, const SOCKID nSockIndex) = 0;

	virtual bool SendMsg2AllClientWithOutHead(const int nMsgID, const std::string& msg) = 0;

	virtual bool SendMsg(const uint16_t nMsgID, const google::protobuf::Message& xData, const SOCKID nSockIndex) = 0;

	virtual bool SendMsg2AllClient(const uint16_t nMsgID, const google::protobuf::Message& xData) = 0;

	virtual bool SendMsg(const uint16_t nMsgID, const google::protobuf::Message& xData, const SOCKID nSockIndex, const GUID nPlayer, const std::vector<GUID>* pClientIDList = NULL) = 0;

	virtual bool SendMsg(const uint16_t nMsgID, const std::string& strData, const SOCKID nSockIndex, const GUID nPlayer, const std::vector<GUID>* pClientIDList = NULL) = 0;

	virtual Net* GetNet() = 0;
};

#endif
