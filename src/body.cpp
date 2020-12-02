#include "../include/algovector.h"
#include "../include/body.h"
#include "../include/txn.h"

#include <iostream>

using namespace std;

Body::~Body(void)
{
}

Body::Body(void)
{
    _txn_count = 0;
}

Body::Body(Txn newTxn)
{
    _txns.push_back(newTxn);
    _txn_count = 1;
}

Body::Body(algoVector<Txn> Txns)
{
    _txns = Txns;
    _txn_count = Txns.size();
}

void Body::setTxnCount(size_t txn_count)
{
    _txn_count = txn_count;
}

const size_t &Body::getTxnCount(void) const
{
    return _txn_count;
}

const algoVector<Txn> &Body::getTxns(void) const
{
    return _txns;
}
void Body::addTxn(Txn newTxn)
{
    _txns.push_back(newTxn);
    _txn_count = _txn_count + 1;
}

const string Body::cat() const
{
    string concatTxns = "";
    if (_txn_count == 0)
    {
        return concatTxns.append("0\n");
    }
    concatTxns.append(to_string(_txn_count));
    concatTxns.append("\n");
    for (size_t i = 0; i < _txn_count; i++)
    {
        concatTxns.append(to_string(_txns[i].getNTxIn()));
        concatTxns.append("\n");
        for (size_t j = 0; j < _txns[i].getNTxIn(); ++j)
        {
            concatTxns.append((_txns[i].getInputs())[j].getAddr());
            concatTxns.append(" ");
            concatTxns.append(to_string((_txns[i].getInputs())[j].getOutpointIdx()));
            concatTxns.append(" ");
            concatTxns.append((_txns[i].getInputs())[j].getOutpointTxId());
            concatTxns.append("\n");
        }
        concatTxns.append(to_string(_txns[i].getNTxOut()));
        concatTxns.append("\n");

        for (size_t j = 0; j < _txns[i].getNTxOut(); ++j)
        {
            concatTxns.append(to_string((_txns[i].getOutputs())[j].getValue()));
            concatTxns.append(" ");
            concatTxns.append((_txns[i].getOutputs())[j].getAddr());
            if (j != _txns[i].getNTxOut() - 1)
                concatTxns.append("\n");
        }
        concatTxns.append("\n");
    }

    return concatTxns;
}

ostream &operator<<(ostream &os, Body b)
{
    return os << b.cat();
}