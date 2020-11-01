#ifndef _BODY_H_
#define _BODY_H_

#include <cstdlib>
#include <vector>

#include "../include/txns.h"

using namespace std;

class Body
{
    public:
        Body();
        size_t getTxnCount(void);
        void setTxnCount(size_t txn_count);
    private:
        size_t _txn_count;
        vector<Txns> _txns;
};

#endif /** _BODY_H_ */