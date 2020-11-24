#ifndef _BODY_H_
#define _BODY_H_

#include <cstdlib>

#include "../include/txn.h"
#include "../include/sha256.h"
#include "../include/algovector.h"

using namespace std;

class Body
{
public:
    Body();
    Body(vector<Txn> Txns);
    Body(Txn);
    size_t getTxnCount(void);
    void setTxnCount(size_t txn_count);
    void addTxn(Txn);
    string cat();
    friend ostream &operator<<(ostream &, Body);

private:
    size_t _txn_count;
    algoVector<Txn> _txns;
};

#endif /** _BODY_H_ */