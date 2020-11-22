#include "../include/balance.h"
#include "../include/error.h"
#include <iostream>
#include <string>
#include <bitset>

Balance::Balance()
{
}

Balance::Balance(string user, float value)
{
    _data.insert({user, value});
}

Balance::~Balance()
{
}

const float Balance::getUserBalance(const string &user) const
{
    if (_data.find(user) == _data.end())
    {
        return 0;
    }
    else
        return _data.at(user);
}

const unordered_map<string, float> Balance::getData()
{
    return _data;
}

const bool Balance::isEmpty()
{
    return _data.empty();
}

void Balance::clear()
{
    _data.clear();
}
void Balance::update(string user, float value)
{
    if (_data.find(user) == _data.end())
        _data.insert({user, value});
    else
        _data.at(user) = value;
}

ostream &operator<<(ostream &os, Balance b)
{
    ostringstream oss;

    for (auto i : b.getData())
    {
        oss << "{" << i.first << ": " << i.second << "}\n";
    }

    return os << oss.str() << endl;
}
