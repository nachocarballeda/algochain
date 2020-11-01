#include "../include/body.h"
#include "../include/txns.h"

#include <iostream>
#include <vector>

using namespace std;

Body::Body(void)
{
    cout << "Body Constructor was called." << endl;
    Txns txns0; //This is only for testing the txns constructor
    _txns.push_back(txns0);
}

void Body::setTxnCount(size_t txn_count)
{
    _txn_count = txn_count;
}

size_t Body::getTxnCount(void)
{
    return _txn_count;
}
