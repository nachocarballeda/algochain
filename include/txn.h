#ifndef _TXN_H_
#define _TXN_H_

#include <cstdlib>

#include "../include/algovector.h"
#include "../include/output.h"
#include "../include/input.h"
#include "../include/outpoint.h"
#include "../include/sha256.h"

using namespace std;

class Txn
{
public:
    Txn(); //default
    Txn(size_t, algoVector<Input>, size_t, algoVector<Output>);
    ~Txn();
    size_t getNTxIn();
    algoVector<Input> getInputs();
    size_t getNTxOut();
    algoVector<Output> getOutputs();
    void addInput(Input);
    void addOutput(Output);
    const int findIdx(const string &);
    string cat();

private:
    size_t _n_tx_in;
    algoVector<Input> _inputs;
    size_t _n_tx_out;
    algoVector<Output> _outputs;
};

#endif /** _TXN_H_ */