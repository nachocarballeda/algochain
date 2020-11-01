#ifndef _BLOCK_HEADER_H_
#define _BLOCK_HEADER_H_

#include <cstdlib>

using namespace std;

class BlockHeader
{
    public:
        BlockHeader();
        char* getPrevBlock(void);
        //getTxnsHash
        //set & getBits
        //set & getNonce
    private:
        char _prev_block[32];
        char _txns_hash[32];
        size_t _bits;
        size_t _nonce;
};

#endif /** _BLOCK_HEADER_H_ */