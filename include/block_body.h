#ifndef _BLOCK_BODY_H_
#define _BLOCK_BODY_H_

#include <cstdlib>

class BlockBody
{
    public:
        BlockBody();
        size_t getTxnCount(void);
        //addTxn
        //getTxn
    private:
        std::size_t txn_count;
        //array of class txns
};

#endif /** _BLOCK_BODY_H_ */