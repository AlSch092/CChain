#ifndef TESTCHAIN_BLOCK_H
#define TESTCHAIN_BLOCK_H
#define BLOCK_MAX_TRANSACTIONS 100 //this needs to be calculated in some sophisticated way... each transaction gets x bytes of data, and we have a list of transactions, with each block containing some fixed number of transactions..

#pragma once
#include <cstdint>
#include <iostream>
#include <sstream>
#include <list>
#include "Transaction.hpp"

//transactions are hashed into eachother, merkle tree hashes T(a), T(b), then the root hashes T(ab) with T(cd) on other leafs to get the merkle root...

using namespace std;

class Block { //blocks have different merkle roots

public:
    string sHash;
    string sPrevHash;

    Block(uint32_t nIndexIn, const string& sDataIn);
    Block(const string& sDataIn);

    void MineBlock(uint32_t nDifficulty);

    Block* LeftLink;
    Block* RightLink;

    uint32_t GetTransactionCount() { return this->nTransactions; }
    time_t GetTimestamp() { return this->_tTime; }
    uint32_t GetIndex() { return this->_nIndex; }
    uint32_t GetNonce() { return this->_nNonce; }
    string GetBlockData() { return this->_sData; }

    list<Transaction*> GetTransactions() { return this->Transactions; }

private:
    
    uint32_t _nIndex; //nBlock
    
    uint32_t _nNonce; //Cryptographic nonce
    
    string _sData; //each block is supposed to hold a certain number of transactions. Now the question arises, how to store these transactions within a block?
    string _sMerkleRoot;
    time_t _tTime; //timestamp

    uint32_t nTransactions;
    list<Transaction*> Transactions;

    string _CalculateHash() const;
};

#endif //TESTCHAIN_BLOCK_H
