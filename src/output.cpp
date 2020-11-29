#include "../include/output.h"

#include <iostream>

using namespace std;

Output::Output()
{
}

Output::Output(string a, float v)
{
    _addr = a;
    _value = v;
}

Output::~Output()
{
}

const string &Output::getAddr() const
{
    return _addr;
}

const size_t Output::getValue() const
{
    return _value;
}