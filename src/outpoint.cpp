#include "../include/outpoint.h"

#include <iostream>

using namespace std;

Outpoint::Outpoint()
{
}

Outpoint::Outpoint(string t, size_t id)
{
    tx_id = t;
    idx = id;
};

Outpoint::~Outpoint()
{
}

const string &Outpoint::getTxId() const
{
    return tx_id;
};

const size_t &Outpoint::getIdx() const
{
    return idx;
};
