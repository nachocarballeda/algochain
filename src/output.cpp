#include "../include/output.h"

#include <iostream>

using namespace std;

Output::Output()
{
    cout << "Outputs default constructor was called." << endl;
}

Output::Output(string a, float v)
{
    addr = a;
    value = v;
}

string Output::getAddr()
{
    return addr;
}

size_t Output::getValue()
{
    return value;
}