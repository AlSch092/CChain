#pragma once

#include <WinSock2.h>
#pragma comment (lib, "ws2_32.lib")

class CConnector
{
public:

	SOCKET PeerConnection;


private:
	int SendData(SOCKET s, LPBYTE data, int Length);

	bool PeerConnect(SOCKET s, char* ipAddr, unsigned short port);

};


