#include "Blockchain.hpp"

Blockchain::Blockchain()
{
    _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = 5;
}

void Blockchain::AddBlock(Block bNew)
{
    bNew.sPrevHash = _GetLastBlock().sHash;
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
    this->index += 1;
}

Block Blockchain::_GetLastBlock() const
{
    return _vChain.back();
}

Blockchain* Blockchain::GetFullChain()
{
    Blockchain* b = new Blockchain();
    return b;
}

