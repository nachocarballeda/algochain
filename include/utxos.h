#ifndef _UTXOS_H_
#define _UTXOS_H_

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

class Utxo_node
{

    friend class Utxos;

public:
    Utxo_node(const string &tx_hash, Txn &tx)
    {
        _tx_hash = tx_hash;
        _txn = tx;
    }
    const string &getTxnHash() { return _tx_hash; }
    const Txn getTxn() { return _txn; }

private:
    string _tx_hash;
    Txn _txn;
};

class Utxos
{
public:
    Utxos();
    ~Utxos();
    const unordered_map<string, string> getData();
    const string &getUserUtxoHash(const string &) const;
    const size_t findUtxoIdx(const string &);

    const bool isEmpty();

    void clear();

    void update(const string &, const string &tx_hash, Txn &txn);

private:
    unordered_map<string, Utxo_node> _data;
};

#endif /** _UTXOS_H_ */