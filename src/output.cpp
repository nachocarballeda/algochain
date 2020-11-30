#include "../include/output.h"

#include <iostream>

using namespace std;

Output::Output()
{
}

Output::Output(string a, double v)
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

double Output::getValue()
{
    return value;
}