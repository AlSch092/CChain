#pragma once
#include <iostream>
#include <string>

using namespace std;

class CContract //transaction can be done on a ... contract
{

public:



private:

	uint64_t DeployerPubKey;

	time_t _timeDeployed;

	uint64_t _balance = 0;

	bool _isTokenContract = false;

protected:

	string _sData;

};