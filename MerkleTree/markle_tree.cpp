#include <iostream>
#include <iomanip>
#include "merkle_tree.hpp"
#include "Blockchain.hpp"

MerkleTree::MerkleTree() {
    this->root = 0;
}

MerkleTree::MerkleTree(std::vector<Block*> blocks) {
    
    std::vector<Block*> nodes;
    while (blocks.size() != 1) {
        //printNodeHashes(blocks);
        for (unsigned int l = 0, n = 0; l < blocks.size(); l = l + 2, n++) {
            if (l != blocks.size() - 1) { // checks for adjacent block
                nodes.push_back(new Block(hash_sha256(blocks[l]->sHash + blocks[l + 1]->sHash))); // combine and hash adjacent blocks
              
                //nodes[n]->left = blocks[l]; // assign children
               // nodes[n]->right = blocks[l + 1];
            }
            else {
                nodes.push_back(blocks[l]);
            }
        }
        std::cout << "\n";
        blocks = nodes;
        nodes.clear();

    }
    this->root = blocks[0];
}

MerkleTree::~MerkleTree() {
    deleteTree(root);
    std::cout << "Tree deleted" << std::endl;
}

void MerkleTree::printTree(Block* n, int indent) {
    if (n) {
        if (n->LeftLink) {
            printTree(n->LeftLink, indent + 4);
        }
        if (n->RightLink) {
            printTree(n->RightLink, indent + 4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        std::cout << n->sHash[0] << "\n ";
    }
}

void MerkleTree::deleteTree(Block* n) {
    if (n) {
        deleteTree(n->LeftLink);
        deleteTree(n->RightLink);
        n = NULL;
        delete n;
    }
}