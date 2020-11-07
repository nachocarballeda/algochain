#include "../include/outpoint.h"

#include <iostream>

using namespace std;

Outpoint::Outpoint()
{
    cout << "Outpoints Constructor was called." << endl;
}

Outpoint::Outpoint(string t, size_t id)
{
    tx_id = t;
    idx = id;
};

string Outpoint::getTxId()
{
    return tx_id;
};

size_t Outpoint::getIdx()
{
    return idx;
};
