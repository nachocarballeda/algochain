#ifndef _TXNS_MEMO_H_
#define _TXNS_MEMO_H_

#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include "../include/output.h"
#include "../include/input.h"
#include "../include/outpoint.h"
#include "../include/txn.h"

using namespace std;

class TxnsMemo
{
public:
    TxnsMemo();
    ~TxnsMemo();
    const unordered_map<string, Txn *> &getData() const;

    const bool isEmpty() const;

    void clear();
    void update(const string &, Txn *);

private:
    unordered_map<string, Txn *> _data;
};

#endif /** _TXNS_MEMO_H_ */