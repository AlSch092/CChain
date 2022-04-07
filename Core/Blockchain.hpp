#ifndef TESTCHAIN_BLOCKCHAIN_H
#define TESTCHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.hpp"
#include "../Network/CConnector.hpp"
#include "../MerkleTree/merkle_tree.hpp"

using namespace std;

class Blockchain {
public:
    Blockchain();

    void AddBlock(Block bNew);

    CConnector* GetClient() { return this->Networker; }
    MerkleTree* GetTree() { return this->hashTree; }

    uint32_t index = 0;

private:

    uint32_t _nDifficulty;
    vector<Block> _vChain; //Linked list- This is the structure of the blockchain itself, which is a linked list of hash pointers

    Block _GetLastBlock() const;

    Blockchain* GetFullChain();

    CConnector* Networker = new CConnector();
    
    MerkleTree* hashTree;

};

#endif //TESTCHAIN_BLOCKCHAIN_H
