#include "../include/txn.h"
#include "../include/output.h"
#include "../include/input.h"

#include <iostream>

using namespace std;

Txn::Txn()
{
    cout << "Txns Constructor was called." << endl;
}

Txn::Txn(size_t nti, vector<Input> in, size_t nto, vector<Output> out)
{
    _n_tx_in = nti;
    _inputs = in;
    _n_tx_out = nto;
    _outputs = out;
}
const size_t &Txn::get_n_tx_in()
{
    return _n_tx_in;
}
const vector<Input> &Txn::get_inputs()
{
    return _inputs;
}
const size_t &Txn::get_n_tx_out()
{
    return _n_tx_in;
}
const vector<Output> &Txn::get_outputs()
{
    return _outputs;
}