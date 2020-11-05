#ifndef _INPUTS_H_
#define _INPUTS_H_

#include <cstdlib>
#include <vector>

#include "../include/outpoint.h"

using namespace std;

class Input
{
public:
    Input();
    Input(vector<char> &, vector<char> &, size_t);
    const vector<char> &get_addr();
    const vector<char> &get_outpoint_tx_id();
    const size_t &get_outpoint_idx();

private:
    static const size_t ADDR_MAX_SIZE = 32;
    vector<char> addr;
    Outpoint _outpoint;
};

#endif /** _INPUTS_H_ */