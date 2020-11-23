#ifndef _TXN_H_
#define _TXN_H_

#include <cstdlib>
#include <vector>

#include "../include/output.h"
#include "../include/input.h"
#include "../include/outpoint.h"
#include "../include/sha256.h"

using namespace std;

class Txn
{
public:
    Txn(); //default
    Txn(size_t, vector<Input>, size_t, vector<Output>);
    size_t getNTxIn();
    vector<Input> getInputs();
    size_t getNTxOut();
    vector<Output> getOutputs();
    void addInput(Input);
    void addOutput(Output);
    const int findIdx(const string &);
    string cat();

private:
    size_t _n_tx_in;
    vector<Input> _inputs;
    size_t _n_tx_out;
    vector<Output> _outputs;
};

#endif /** _TXN_H_ */