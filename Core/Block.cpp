#include "Block.hpp"
#include "sha256.hpp"

Block::Block(uint32_t nIndexIn, const string& sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
    _nNonce = 0;
    _tTime = time(nullptr);
    sHash = _CalculateHash();
}

Block::Block(const string& sDataIn) : _sData(sDataIn)
{
    _nNonce = 0;
    _tTime = time(nullptr);
    sHash = _CalculateHash();

}

void Block::MineBlock(uint32_t nDifficulty)
{
    char* cstr = new char[(nDifficulty+1)];
    
    for (uint32_t i = 0; i < nDifficulty; ++i) //forms a string '0000' of nDifficulty chars, when sHash first nDifficulty chars is '0', we have a good enough case.
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty+1] = '\0';

    string str(cstr);

    printf("str: %s, cstr: %s\n", cstr, str.c_str());

    do
    {
        _nNonce++;
        sHash = _CalculateHash();
        printf("sHash: %s\n", sHash.c_str());

    } while (sHash.substr(0, nDifficulty) != str); //sHash: 7c924faf229ebf1f0b5a81644b33d0265d0637735779ace4b614cfb50e73639d. for a 'good enough' case, the first nDifficlty digits must be '0', such as 00000faf229ebf...

    cout << "Block mined: " << sHash << endl;

    delete[] cstr;
}

inline string Block::_CalculateHash() const
{
    stringstream ss;
    ss << _nIndex << sPrevHash << _tTime << _sData << _nNonce;

    return sha256(ss.str());
}
