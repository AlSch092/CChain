#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Transaction
{
public:

	string GetData() { return this->sData; }

private:
	string sData;

};