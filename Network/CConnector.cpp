#include "CConnector.hpp"

int CConnector::SendData(SOCKET s, LPBYTE data, int Length)
{
	int bytesSent = send(s, (const char*)data, Length, 0);

	return bytesSent;
}

bool CConnector::PeerConnect(SOCKET s, char* ipAddr, unsigned short port)
{



	return false;
}