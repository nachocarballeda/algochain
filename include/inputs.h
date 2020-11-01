#ifndef _INPUTS_H_
#define _INPUTS_H_

#include <cstdlib>
#include <vector>

#include "../include/outpoint.h"

using namespace std;

class Inputs
{
    public:
        Inputs();
    private:
        char addr[32];
        Outpoint _outpoint;
};

#endif /** _INPUTS_H_ */