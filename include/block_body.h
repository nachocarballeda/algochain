#ifndef _BLOCK_BODY_H_
#define _BLOCK_BODY_H_

#include <cstdlib>

using namespace std;

class BlockBody
{
    public:
        BlockBody();
        size_t getTxnCount(void);
        void setTxnCount(size_t txn_count);
        //addTxn
        //getTxn
    private:
        size_t _txn_count;
        //array of class txns
};

#endif /** _BLOCK_BODY_H_ */