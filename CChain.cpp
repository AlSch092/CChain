/*
FULL-NODE Client for CChain... Started April 5 2022
*/

#include "Blockchain.hpp"

int main()
{
    std::vector<Block*> leaves;
    //create sample data
    leaves.push_back(new Block(hash_sha256("{tx=134634656, e-pub=0x234562, value=100, recv_pub=0x12345}")));

    MerkleTree* hashTree = new MerkleTree(leaves);
    std::cout << hashTree->root->sHash << std::endl;
    system("pause");

    hashTree->printTree(hashTree->root, 0);

    for (unsigned int k = 0; k < leaves.size(); k++) {
        delete leaves[k];
    }

    delete hashTree;

    system("pause");

    Blockchain bChain = Blockchain();

    cout << "Mining block 1..." << endl; //todo: turn block data into list of transactions
    bChain.AddBlock(Block(1, "Block 1 Data"));

    cout << "Mining block 2..." << endl;
    bChain.AddBlock(Block(2, "Block 2 Data"));

    cout << "Mining block 3..." << endl;
    bChain.AddBlock(Block(3, "Block 3 Data"));

    return 0;
}
