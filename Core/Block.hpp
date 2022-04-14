#ifndef TESTCHAIN_BLOCK_H
#define TESTCHAIN_BLOCK_H
#define BLOCK_MAX_TRANSACTIONS 100 //todo: figure out way to calculate this

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

    Block* LeftLink;
    Block* RightLink;

    Block(uint32_t nIndexIn, uint32_t nDifficulty, const string& sDataIn);

    void MineBlock(uint32_t nDifficulty); //Partial nodes do not mine

    uint32_t GetTransactionCount() { return this->_nTransactions; }
    time_t GetTimestamp() { return this->_tTime; }

    void SetIndex(uint32_t index) { this->_nIndex = index; }
    uint32_t GetIndex() { return this->_nIndex; }

    uint32_t GetNonce() { return this->_nNonce; }

    string GetBlockData() { return this->_sData; }
    void SetBlockData(string sData) { this->_sData = sData; }

    list<Transaction*> GetTransactions() { return this->Transactions; }

    bool AddTransaction(Transaction* Tx)
    {
        if (Tx->GetData() != NULL)
        {
            this->GetTransactions().push_back(Tx);
            return true;
        }

        return false;
    }


    uint32_t GetDifficulty() { return this->_nDifficulty; }
    void SetBlockDifficulty(uint32_t _nDiff) { this->_nDifficulty = _nDiff; }

    bool SetNeighbor(Block* neighbor, bool LeftRightNeighbor);

private:
    
    uint32_t _nIndex; //nBlock
    
    uint32_t _nNonce; //Cryptographic nonce
    
    string _sData; //each block is supposed to hold a certain number of transactions. Now the question arises, how to store these transactions within a block?
    string _sMerkleRoot;
    time_t _tTime; //timestamp

    uint32_t _nTransactions;
    list<Transaction*> Transactions;

    uint32_t _nDifficulty; //blocks can have different difficulties

    string _CalculateHash() const;

    uint32_t _nReward; //block reward

    bool _isOrphan; //A competing miner may broadcast its block just after the first miner, and also link its block to the Blockchain. However, the nodes will notice the time difference and its block will become an orphan block, it’ll no longer participate in the active chain.
};

#endif //TESTCHAIN_BLOCK_H
