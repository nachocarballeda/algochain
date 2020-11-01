#ifndef _HEADER_H_
#define _HEADER_H_

#include <cstdlib>

using namespace std;

class Header
{
    public:
        Header();
        char* getPrevBlock(void);
    private:
        char _prev_block[32];
        char _txns_hash[32];
        size_t _bits;
        size_t _nonce;
};

#endif /** _HEADER_H_ */