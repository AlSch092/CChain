#ifndef MERKLE_TREE_H
#define MERKLE_TREE_H

#include "Block.hpp"
#include "picosha2.h"
#include "misc.h"
#include <vector>
#include <string>

/*
For example, if Bitcoin didn’t have Merkle Trees, every node on the network would need to maintain a full copy 
of every transaction that has ever happened on Bitcoin..


*/
struct MerkleTree {
    Block* root;
    MerkleTree();
    MerkleTree(std::vector<Block*> blocks);
    ~MerkleTree();
    void printTree(Block* n, int indent);
    void deleteTree(Block* n);
};


#endif /* MERKLE_TREE_H */