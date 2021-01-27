#ifndef _INPUTS_H_
#define _INPUTS_H_

#include <cstdlib>
#include <string>

#include "../include/algovector.h"
#include "../include/outpoint.h"
#include "../include/algovector.h"

using namespace std;

class Input
{
public:
    Input();
    Input(string, string, size_t);
    ~Input();
    const string &getAddr() const;
    const string &getOutpointTxId() const;
    const size_t &getOutpointIdx() const;

private:
    string addr;
    Outpoint _outpoint;
};

#endif /** _INPUTS_H_ */