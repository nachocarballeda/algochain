#ifndef _INPUTS_H_
#define _INPUTS_H_

#include <cstdlib>
#include <string>

#include "../include/algovector.h"
#include "../include/outpoint.h"

using namespace std;

class Input
{
public:
    Input();
    Input(string, string, size_t);
    ~Input();
    string getAddr();
    string getOutpointTxId();
    size_t getOutpointIdx();

private:
    string addr;
    Outpoint _outpoint;
};

#endif /** _INPUTS_H_ */