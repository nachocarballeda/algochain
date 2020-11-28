#ifndef _MEMPOOL_H_
#define _MEMPOOL_H_
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

#include "../include/txn.h"
#include "../include/error.h"
#include "../include/balance.h"
#include "../include/algovector.h"

using namespace std;

class Mempool
{
public:
    Mempool();
    Mempool(const algoVector<Txn> &, Balance);
    ~Mempool();

    const Balance &getNewBalance() const;
    const algoVector<Txn> &getNewTxns() const;

    void addTxn(const Txn txn);
    void setNewBalance(const Balance);
    void update(const algoVector<Txn> &, Balance);
    void clear();

private:
    algoVector<Txn> _newTxns;
    Balance _newBalance;
};

#endif