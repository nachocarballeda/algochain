#include "../include/input.h"

#include <iostream>

using namespace std;

Input::Input()
{
    cout << "Inputs Constructor was called." << endl;
}

Input::Input(string a, string tx_id, size_t idx) : _outpoint(tx_id, idx)
{
    addr = a;
}

string Input::getAddr()
{
    return addr;
}

string Input::getOutpointTxId()
{
    return _outpoint.getTxId();
}

size_t Input::getOutpointIdx()
{
    return _outpoint.getIdx();
}