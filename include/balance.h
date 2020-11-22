#ifndef _BALANCE_H_
#define _BALANCE_H_
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include "../include/error.h"

using namespace std;

class Balance
{
public:
    Balance();
    Balance(string, float);
    ~Balance();
    const float getUserBalance(const string &) const;
    const unordered_map<string, float> getData();
    void update(string, float); //actualizar balance de usuarios
    const bool isEmpty();
    friend ostream &operator<<(ostream &, Balance);

private:
    unordered_map<string, float> _data;
};

#endif