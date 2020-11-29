#include <cstdlib>
#include <vector>
#include <unordered_map>

#include "../include/output.h"
#include "../include/input.h"
#include "../include/outpoint.h"
#include "../include/txns_memo.h"

using namespace std;

TxnsMemo::TxnsMemo()
{
}

TxnsMemo::~TxnsMemo()
{
}

const bool TxnsMemo::isEmpty() const
{
    return _data.empty();
}

void TxnsMemo::clear()
{
    _data.clear();
}
void TxnsMemo::update(const string &tx_hash, Txn *txn)
{

    if (_data.find(tx_hash) == _data.end())
        _data.insert({tx_hash, txn});
    else
        _data.at(tx_hash) = txn;
}

const unordered_map<string, Txn *> &TxnsMemo::getData() const
{
    return _data;
}