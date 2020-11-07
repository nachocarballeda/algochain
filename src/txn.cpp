#include "../include/txn.h"
#include "../include/output.h"
#include "../include/input.h"

#include <iostream>

using namespace std;

Txn::Txn()
{
    cout << "Txns Constructor was called." << endl;
    _n_tx_in = 0;
    _n_tx_out = 0;
}

Txn::Txn(size_t nti, vector<Input> in, size_t nto, vector<Output> out)
{
    _n_tx_in = nti;
    _inputs = in;
    _n_tx_out = nto;
    _outputs = out;
}
size_t Txn::getNTxIn()
{
    return _n_tx_in;
}
vector<Input> Txn::getInputs()
{
    return _inputs;
}
size_t Txn::getNTxOut()
{
    return _n_tx_out;
}
vector<Output> Txn::getOutputs()
{
    return _outputs;
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