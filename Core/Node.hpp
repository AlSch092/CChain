#pragma once
#include "Network/CBroadcaster.hpp"
#include "Core/Blockchain.hpp"

class Node //full node class
{
public:

	Blockchain* GetBlockchain() { return this->Chain; }
	CBroadcaster* GetBroadcaster() { return this->Broadcaster; }


private:

	CBroadcaster* Broadcaster = new CBroadcaster();
	Blockchain* Chain = new Blockchain(); 

};
