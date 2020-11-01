#include "../include/block_body.h"

#include <iostream>

using namespace std;

BlockBody::BlockBody(void)
{
    cout << "Body Constructor was called." << endl;
}

void BlockBody::setTxnCount(size_t txn_count)
{
    _txn_count = txn_count;
}

size_t BlockBody::getTxnCount(void)
{
    return _txn_count;
}
