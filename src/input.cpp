#include "../include/input.h"

#include <iostream>

using namespace std;

Input::Input()
{
    cout << "Inputs Constructor was called." << endl;
}

Input::Input(vector<char> &a, vector<char> &tx_id, size_t idx) : _outpoint(tx_id, idx)
{
    if (a.size() == ADDR_MAX_SIZE)
    {
        addr = a;
    };
}

const vector<char> &Input::get_addr()
{
    return addr;
}

const vector<char> &Input::get_outpoint_tx_id()
{
    return _outpoint.get_tx_id();
}

const size_t &Input::get_outpoint_idx()
{
    return _outpoint.get_idx();
}