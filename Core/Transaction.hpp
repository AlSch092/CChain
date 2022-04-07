#pragma once
#include <iostream>
#include <string.h>

using namespace std;

typedef unsigned char byte;

class Transaction
{
public:

	byte* GetData() { return this->bData; }

	void Initialize(byte* bDataIn, uint32_t DataLen);

private:

	byte* bData; //we should be using as little bytes as possible? stored as JSON text to represent each request?
	uint32_t _nUsedBytes;


	uint64_t _nPowderUsedByTransaction; //similar to 'gas' of ethereum
	time_t _tTimestamp; //tx timestamp

	uint32_t RequestedBy; //transaction author, similar to public key of msg.sender in eth
};
