#include "../include/outpoint.h"

#include <iostream>

using namespace std;

Outpoint::Outpoint()
{
    cout << "Outpoints Constructor was called." << endl;
}

Outpoint::Outpoint(vector<char> &t, size_t id)
{
    if (t.size() == TX_ID_MAX_SIZE)
    {
        tx_id = t;
        idx = id;
    };
};

const vector<char> &Outpoint::get_tx_id()
{
    return tx_id;
};

const size_t &Outpoint::get_idx()
{
    return idx;
};
