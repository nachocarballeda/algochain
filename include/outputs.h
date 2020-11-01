#ifndef _OUTPUTS_H_
#define _OUTPUTS_H_

#include <cstdlib>

using namespace std;

class Outputs
{
    public:
        Outputs();
    private:
        char addr[32];
        size_t value;
};

#endif /** _OUTPUTS_H_ */