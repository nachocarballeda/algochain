#ifndef _BLOCK_HEADER_H_
#define _BLOCK_HEADER_H_

#include <cstdlib>

class BlockHeader
{
    public:
        BlockHeader();
        char* getPrevBlock(void);
        //getTxnsHash
        //set & getBits
        //set & getNonce
    private:
        char prev_block[32];
        char txns_hash[32];
        std::size_t bits;
        std::size_t nonce;
};

#endif /** _BLOCK_HEADER_H_ */