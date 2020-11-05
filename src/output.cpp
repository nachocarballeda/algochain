#include "../include/output.h"

#include <iostream>

using namespace std;

Output::Output()
{
    cout << "Outputs default constructor was called." << endl;
}

Output::Output(vector<char> &a, size_t v)
{
    if (a.size() == ADDR_MAX_SIZE)
    {
        addr = a;
        value = v;
    };
}

const vector<char> &Output::get_addr()
{
    return addr;
}

const size_t &Output::get_value()
{
    return value;
}