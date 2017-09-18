#include "NetModule.h"
#include "Network.h"
// NetModule::NetModule(NFIPluginManager * p)
// {
// 	pPluginManager = p;
// 
// 	mnBufferSize = 0;
// 	nLastTime = GetPluginManager()->GetNowTime();
// 	m_pNet = NULL;
// }

NetModule::~NetModule()
{
	if (m_pNet)
	{
		m_pNet->Final();
	}

	delete m_pNet;
	m_pNet = NULL;
}
void NetModule::Initialization(const char * strIP, const unsigned short nPort)
{
	m_pNet = NEW Network(this, &NetModule::OnReceiveNetPack, &NetModule::OnSocketNetEvent);
	m_pNet->ExpandBufferSize(mnBufferSize);
	m_pNet->Initialization(strIP, nPort);
}

int NetModule::Initialization(const unsigned int nMaxClient, const unsigned short nPort, const int nCpuCount)
{
	m_pNet = NEW Network(this, &NetModule::OnReceiveNetPack, &NetModule::OnSocketNetEvent);
	m_pNet->ExpandBufferSize(mnBufferSize);
	return m_pNet->Initialization(nMaxClient, nPort, nCpuCount);
}

int NetModule::ExpandBufferSize(const unsigned int size)
{
	if (size > 0)
	{
		mnBufferSize = size;
		if (m_pNet)
		{
			m_pNet->ExpandBufferSize(mnBufferSize);
		}
	}

	return mnBufferSize;
}

void NetModule::RemoveReceiveCallBack(const int nMsgID)
{
	std::map<int, NET_RECEIVE_FUNCTOR_PTR>::iterator it = mxReceiveCallBack.find(nMsgID);
	if (mxReceiveCallBack.end() != it)
	{
		mxReceiveCallBack.erase(it);
	}
}

bool NetModule::AddReceiveCallBack(const int nMsgID, const NET_RECEIVE_FUNCTOR_PTR & cb)
{
	if (mxReceiveCallBack.find(nMsgID) != mxReceiveCallBack.end())
	{
		return false;
	}

	mxReceiveCallBack.insert(std::map<int, NET_RECEIVE_FUNCTOR_PTR>::value_type(nMsgID, cb));

	return true;
}

bool NetModule::AddReceiveCallBack(const NET_RECEIVE_FUNCTOR_PTR & cb)
{
	mxCallBackList.push_back(cb);

	return true;
}

bool NetModule::AddEventCallBack(const NET_EVENT_FUNCTOR_PTR & cb)
{
	mxEventCallBackList.push_back(cb);

	return true;
}

bool NetModule::Execute()
{
	if (!m_pNet)
	{
		return false;
	}


	KeepAlive();

	return m_pNet->Execute();
}

bool NetModule::SendMsgWithOutHead(const int nMsgID, const std::string & msg, const SOCKID nSockIndex)
{
	return m_pNet->SendMsgWithOutHead(nMsgID, msg.c_str(), (uint32_t)msg.length(), nSockIndex);
}

bool NetModule::SendMsgToAllClientWithOutHead(const int nMsgID, const std::string & msg)
{
	return m_pNet->SendMsgToAllClientWithOutHead(nMsgID, msg.c_str(), (uint32_t)msg.length());
}

bool NetModule::SendMsg(const uint16_t nMsgID, const google::protobuf::Message & xData, const SOCKID nSockIndex)
{
	Msg::MsgBase xMsg;
	if (!xData.SerializeToString(xMsg.mutable_msg_data()))
	{
		char szData[MAX_PATH] = { 0 };
		NFSPRINTF(szData, MAX_PATH, "Send Message to %d Failed For Serialize of MsgData, MessageID: %d\n", (int)nSockIndex, nMsgID);

		return false;
	}

	Msg::Ident* pPlayerID = xMsg.mutable_player_id();
	*pPlayerID = IDToPB(module::GUID());

	std::string strMsg;
	if (!xMsg.SerializeToString(&strMsg))
	{
		char szData[MAX_PATH] = { 0 };
		NFSPRINTF(szData, MAX_PATH, "Send Message to %d Failed For Serialize of MsgBase, MessageID: %d\n", (int)nSockIndex, nMsgID);

		return false;
	}

	SendMsgWithOutHead(nMsgID, strMsg, nSockIndex);

	return true;
}

bool NetModule::SendMsg2AllClient(const uint16_t nMsgID, const google::protobuf::Message & xData)
{
	Msg::MsgBase xMsg;
	if (!xData.SerializeToString(xMsg.mutable_msg_data()))
	{
		char szData[MAX_PATH] = { 0 };
		NFSPRINTF(szData, MAX_PATH, "Send Message to all Failed For Serialize of MsgData, MessageID: %d\n", nMsgID);

		return false;
	}

	Msg::Ident* pPlayerID = xMsg.mutable_player_id();
	*pPlayerID = IDToPB(module::GUID());

	std::string strMsg;
	if (!xMsg.SerializeToString(&strMsg))
	{
		char szData[MAX_PATH] = { 0 };
		NFSPRINTF(szData, MAX_PATH, "Send Message to all Failed For Serialize of MsgBase, MessageID: %d\n", nMsgID);

		return false;
	}

	return SendMsgToAllClientWithOutHead(nMsgID, strMsg);
}

bool NetModule::SendMsg(const uint16_t nMsgID, const google::protobuf::Message & xData, const SOCKID nSockIndex, const module::GUID nPlayer, const std::vector<module::GUID>* pClientIDList)
{
	if (!m_pNet)
	{
		char szData[MAX_PATH] = { 0 };
		NFSPRINTF(szData, MAX_PATH, "Send Message to %d Failed For NULL Of Net, MessageID: %d\n", (int)nSockIndex, nMsgID);

		return false;
	}

	Msg::MsgBase xMsg;
	if (!xData.SerializeToString(xMsg.mutable_msg_data()))
	{
		char szData[MAX_PATH] = { 0 };
		NFSPRINTF(szData, MAX_PATH, "Send Message to %d Failed For Serialize of MsgData, MessageID: %d\n", (int)nSockIndex, nMsgID);

		return false;
	}


	Msg::Ident* pPlayerID = xMsg.mutable_player_id();
	*pPlayerID = IDToPB(nPlayer);
	if (pClientIDList)
	{
		for (int i = 0; i < pClientIDList->size(); ++i)
		{
			const module::GUID& ClientID = (*pClientIDList)[i];

			Msg::Ident* pData = xMsg.add_player_client_list();
			if (pData)
			{
				*pData = IDToPB(ClientID);
			}
		}
	}

	std::string strMsg;
	if (!xMsg.SerializeToString(&strMsg))
	{
		char szData[MAX_PATH] = { 0 };
		NFSPRINTF(szData, MAX_PATH, "Send Message to %d Failed For Serialize of MsgBase, MessageID: %d\n", (int)nSockIndex, nMsgID);

		return false;
	}

	return SendMsgWithOutHead(nMsgID, strMsg, nSockIndex);
}

bool NetModule::SendMsg(const uint16_t nMsgID, const std::string & strData, const SOCKID nSockIndex, const module::GUID nPlayer, const std::vector<module::GUID>* pClientIDList)
{
	if (!m_pNet)
	{
		char szData[MAX_PATH] = { 0 };
		NFSPRINTF(szData, MAX_PATH, "Send Message to %d Failed For NULL Of Net, MessageID: %d\n", (int)nSockIndex, nMsgID);
		//LogSend(szData);

		return false;
	}

	Msg::MsgBase xMsg;
	xMsg.set_msg_data(strData.data(), strData.length());


	Msg::Ident* pPlayerID = xMsg.mutable_player_id();
	*pPlayerID = IDToPB(nPlayer);
	if (pClientIDList)
	{
		for (int i = 0; i < pClientIDList->size(); ++i)
		{
			const module::GUID& ClientID = (*pClientIDList)[i];

			Msg::Ident* pData = xMsg.add_player_client_list();
			if (pData)
			{
				*pData = IDToPB(ClientID);
			}
		}
	}

	std::string strMsg;
	if (!xMsg.SerializeToString(&strMsg))
	{
		char szData[MAX_PATH] = { 0 };
		NFSPRINTF(szData, MAX_PATH, "Send Message to %d Failed For Serialize of MsgBase, MessageID: %d\n", (int)nSockIndex, nMsgID);
		//LogSend(szData);

		return false;
	}

	return SendMsgWithOutHead(nMsgID, strMsg, nSockIndex);
}

Net * NetModule::GetNet()
{
	return m_pNet;
}

void NetModule::OnReceiveNetPack(const SOCKID nSockIndex, const int nMsgID, const char * msg, const uint32_t nLen)
{
	std::map<int, NET_RECEIVE_FUNCTOR_PTR>::iterator it = mxReceiveCallBack.find(nMsgID);
	if (mxReceiveCallBack.end() != it)
	{
		NET_RECEIVE_FUNCTOR_PTR& pFunPtr = it->second;
		NET_RECEIVE_FUNCTOR* pFunc = pFunPtr.get();
		pFunc->operator()(nSockIndex, nMsgID, msg, nLen);
	}
	else
	{
		for (std::list<NET_RECEIVE_FUNCTOR_PTR>::iterator it = mxCallBackList.begin(); it != mxCallBackList.end(); ++it)
		{
			NET_RECEIVE_FUNCTOR_PTR& pFunPtr = *it;
			NET_RECEIVE_FUNCTOR* pFunc = pFunPtr.get();
			pFunc->operator()(nSockIndex, nMsgID, msg, nLen);
		}
	}
}
void NetModule::OnSocketNetEvent(const SOCKID nSockIndex, const NET_EVENT eEvent, Net * pNet)
{
	for (std::list<NET_EVENT_FUNCTOR_PTR>::iterator it = mxEventCallBackList.begin(); it != mxEventCallBackList.end(); ++it)
	{
		NET_EVENT_FUNCTOR_PTR& pFunPtr = *it;
		NET_EVENT_FUNCTOR* pFunc = pFunPtr.get();
		pFunc->operator()(nSockIndex, eEvent, pNet);
	}
}

void NetModule::KeepAlive()
{
	if (!m_pNet)
	{
		return;
	}

	if (m_pNet->IsServer())
	{
		return;
	}

// 	if (nLastTime + 10 > GetPluginManager()->GetNowTime())
// 	{
// 		return;
// 	}
// 
// 	nLastTime = GetPluginManager()->GetNowTime();
// 
// 	Msg::ServerHeartBeat xMsg;
// 	xMsg.set_count(0);
// 
// 	SendMsg(Msg::EGameMsgID::EGMI_STS_HEART_BEAT, xMsg, 0);

}