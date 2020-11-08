#ifndef _BODY_H_
#define _BODY_H_

#include <cstdlib>
#include <vector>

#include "../include/txn.h"
#include "../include/sha256.h"

using namespace std;

class Body
{
public:
    Body();
    size_t getTxnCount(void);
    void setTxnCount(size_t txn_count);
    void addTxn(Txn);
    string cat();
    // string generateTxnsHash();
    friend ostream &operator<<(ostream &, Body); //Operador '<<'.

private:
    size_t _txn_count;
    vector<Txn> _txns;
};

#endif /** _BODY_H_ */