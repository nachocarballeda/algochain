#ifndef _OUTPOINT_H_
#define _OUTPOINT_H_

#include <cstdlib>
#include <vector>

using namespace std;

class Outpoint
{
public:
    Outpoint();
    Outpoint(vector<char> &, size_t);
    const vector<char> &get_tx_id();
    const size_t &get_idx();

private:
    static const size_t TX_ID_MAX_SIZE = 32;
    vector<char> tx_id;
    size_t idx;
};

#endif /** _OUTPOINT_H_ */