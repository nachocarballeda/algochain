#include "../include/algovector.h"
#include "../include/txn.h"
#include "../include/output.h"
#include "../include/input.h"

#include <iostream>

using namespace std;

Txn::Txn()
{
    _n_tx_in = 0;
    _n_tx_out = 0;
}

Txn::Txn(size_t nti, algoVector<Input> in, size_t nto, algoVector<Output> out)
{
    _n_tx_in = nti;
    _inputs = in;
    _n_tx_out = nto;
    _outputs = out;
}

Txn::~Txn()
{
}

const size_t &Txn::getNTxIn() const
{
    return _n_tx_in;
}

const algoVector<Input> &Txn::getInputs() const
{
    return _inputs;
}

const size_t &Txn::getNTxOut() const
{
    return _n_tx_out;
}

const algoVector<Output> &Txn::getOutputs() const
{
    return _outputs;
}

const int Txn::findIdx(const string &user)
{
    for (size_t i = 0; i < _n_tx_out; i++)
    {
        if (_outputs[i].getAddr() == sha256(user))
            return i + 1;
    }
    return 0;
}

void Txn::addInput(Input newInput)
{
    _inputs.push_back(newInput);
    _n_tx_in = _n_tx_in + 1;
}

void Txn::addOutput(Output newOutput)
{
    _outputs.push_back(newOutput);
    _n_tx_out = _n_tx_out + 1;
}

string Txn::cat()
{
    string concatTxns = "";

    concatTxns.append(to_string(this->getNTxIn()));
    concatTxns.append("\n");
    for (size_t j = 0; j < this->getNTxIn(); ++j)
    {
        concatTxns.append((this->getInputs())[j].getAddr());
        concatTxns.append(" ");
        concatTxns.append(to_string((this->getInputs())[j].getOutpointIdx()));
        concatTxns.append(" ");
        concatTxns.append((this->getInputs())[j].getOutpointTxId());
        concatTxns.append("\n");
    }
    concatTxns.append(to_string(this->getNTxOut()));
    concatTxns.append("\n");

    for (size_t j = 0; j < this->getNTxOut(); ++j)
    {
        concatTxns.append(to_string((this->getOutputs())[j].getValue()));
        concatTxns.append(" ");
        concatTxns.append((this->getOutputs())[j].getAddr());
        if (j != this->getNTxOut() - 1)
            concatTxns.append("\n");
    }
    return concatTxns;
}