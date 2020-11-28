#ifndef _BODY_H_
#define _BODY_H_

#include <cstdlib>

#include "../include/algovector.h"
#include "../include/txn.h"
#include "../include/sha256.h"

using namespace std;

class Body
{
public:
    Body();
    Body(algoVector<Txn> Txns);
    Body(Txn);
    ~Body();
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