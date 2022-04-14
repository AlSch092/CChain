#include "Transaction.hpp"

void Transaction::Initialize(byte* bDataIn, uint32_t DataLen)
{
	this->bData = new byte[DataLen];

}

void Transaction::Destroy()
{
	delete[] this->bData;
}
