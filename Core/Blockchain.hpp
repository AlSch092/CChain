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

    Blockchain* GetFullChain();

    void AddBlock(Block* bNew);

    CConnector* GetClient() { return this->Networker; }
    MerkleTree* GetTree() { return this->hashTree; }
    vector<Block*> GetChain() { return this->_vChain; }

    uint32_t index = 0;

    uint32_t GetDifficulty() { return this->_nDifficulty; } //this should be modifiable while nodes are open

private:

    uint32_t _nDifficulty;
    vector<Block*> _vChain; //Linked list- This is the structure of the blockchain itself, which is a linked list of hash pointers

    Block* _GetLastBlock() const;

    CConnector* Networker = new CConnector();
    
    MerkleTree* hashTree = new MerkleTree();

};

#endif //TESTCHAIN_BLOCKCHAIN_H
