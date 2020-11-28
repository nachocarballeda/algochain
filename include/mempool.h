#ifndef _MEMPOOL_H_
#define _MEMPOOL_H_
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

#include "../include/txn.h"
#include "../include/error.h"
#include "../include/balance.h"

using namespace std;

class Mempool
{
public:
    Mempool();
    Mempool(const vector<Txn> &, Balance);
    ~Mempool();

    const Balance &getNewBalance() const;
    const vector<Txn> &getNewTxns() const;

    void addTxn(const Txn txn);
    void setNewBalance(const Balance);
    void update(const vector<Txn> &, Balance);
    void clear();

private:
    vector<Txn> _newTxns;
    Balance _newBalance;
};

#endif