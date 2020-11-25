#include "../include/output.h"

#include <iostream>

using namespace std;

Output::Output()
{
}

Output::Output(string a, float v)
{
    addr = a;
    value = v;
}

Output::~Output()
{
}

string Output::getAddr()
{
    return addr;
}

size_t Output::getValue()
{
    return value;
}