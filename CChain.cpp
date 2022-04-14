#include "Core/Node.hpp"
#define STANDARD_DIFFICULTY 5

int main()
{
    Node* _FullNode = new Node();

    cout << "Mining block 1..." << endl;
    _FullNode->GetBlockchain()->AddBlock(new Block(1, STANDARD_DIFFICULTY, "todo: overload this func for Transaction* , the Tx can be added to block after it's mined and then verified with other nodes."));

    cout << "Mining block 2..." << endl;
    _FullNode->GetBlockchain()->AddBlock(new Block(2, STANDARD_DIFFICULTY, "[tx=1, from=0x0582832493432495, to=0x93249985983535325, nonce=40, ]"));

    return 0;
}
