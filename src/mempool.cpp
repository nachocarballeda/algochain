#include "../include/algovector.h"
#include "../include/balance.h"
#include "../include/error.h"
#include "../include/mempool.h"

#include <iostream>
#include <string>
#include <bitset>

Mempool::Mempool()
{
}

Mempool::Mempool(const algoVector<Txn> &txns, Balance b)
{
    _newTxns = txns;
    _newBalance = b;
}

Mempool::~Mempool()
{
}

void Mempool::update(const algoVector<Txn> &txns, Balance b)
{
    _newTxns = txns;
    _newBalance = b;
}

void Mempool::setNewBalance(const Balance b)
{
    _newBalance = b;
}

void Mempool::addTxn(const Txn txn)
{
    _newTxns.push_back(txn);
}

void Mempool::clear()
{
    Balance aux;
    algoVector<Txn> aux_txn;
    _newTxns = aux_txn;
    _newBalance = aux;
}

const Balance &Mempool::getNewBalance() const
{
    return _newBalance;
}

const algoVector<Txn> &Mempool::getNewTxns() const
{
    return _newTxns;
}