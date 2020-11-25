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

string Outpoint::getTxId()
{
    return tx_id;
};

size_t Outpoint::getIdx()
{
    return idx;
};
