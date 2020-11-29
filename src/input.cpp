#include "../include/input.h"

#include <iostream>

using namespace std;

Input::Input()
{
}

Input::Input(string a, string tx_id, size_t idx) : _outpoint(tx_id, idx)
{
    addr = a;
}

Input::~Input()
{
}

const string &Input::getAddr() const
{
    return addr;
}

const string &Input::getOutpointTxId() const
{
    return _outpoint.getTxId();
}

const size_t &Input::getOutpointIdx() const
{
    return _outpoint.getIdx();
}