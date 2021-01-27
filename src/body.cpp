#include "../include/algovector.h"
#include "../include/body.h"
#include "../include/txn.h"
#include "../include/algovector.h"

#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>

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
            concatTxns.append((_txns[i].getInputs())[j].getOutpointTxId());
            concatTxns.append(" ");
            concatTxns.append(to_string((_txns[i].getInputs())[j].getOutpointIdx()));
            concatTxns.append(" ");
            concatTxns.append((_txns[i].getInputs())[j].getAddr());
            concatTxns.append("\n");
        }
        concatTxns.append(to_string(_txns[i].getNTxOut()));
        concatTxns.append("\n");

        for (size_t j = 0; j < _txns[i].getNTxOut(); ++j)
        {
            std::stringstream s;
            double _integral_part;
            double _fract_part;
            double _original_value;
            _original_value = (_txns[i].getOutputs())[j].getValue();
            _fract_part = modf(_original_value, &_integral_part);
            if( _fract_part == 0)
                s << std::fixed << std::setprecision(0) << _integral_part;
            else
                s << std::fixed << std::setprecision(1) << _original_value;
            concatTxns.append(s.str());
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