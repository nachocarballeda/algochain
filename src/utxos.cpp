#include <cstdlib>
#include <vector>
#include <unordered_map>

#include "../include/output.h"
#include "../include/input.h"
#include "../include/outpoint.h"
#include "../include/utxos.h"

using namespace std;

Utxos::Utxos()
{
}

Utxos::~Utxos()
{
}

const string Utxos::getUserUtxoHash(const string &user) const
{
    if (_data.find(user) == _data.end())
    {
        return "";
    }
    else
        return _data.at(user)._tx_hash;
}

const size_t Utxos::findUtxoIdx(const string &user) const
{
    if (_data.find(user) == _data.end())
    {
        return 0;
    }
    else
    {
        Txn aux = _data.at(user).getTxn();
        return aux.findIdx(user);
    }
}

const bool Utxos::isEmpty() const
{
    return _data.empty();
}

void Utxos::clear()
{
    _data.clear();
}
void Utxos::update(const string &user, const string &tx_hash, Txn &txn)
{
    Utxo_node utxo(tx_hash, txn);

    if (_data.find(user) == _data.end())
        _data.insert({user, utxo});
    else
        _data.at(user) = utxo;
}
