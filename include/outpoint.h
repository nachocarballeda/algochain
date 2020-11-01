#ifndef _OUTPOINT_H_
#define _OUTPOINT_H_

#include <cstdlib>

using namespace std;

class Outpoint
{
    public:
        Outpoint();
    private:
        char tx_id[32];
        size_t idx;
};

#endif /** _OUTPOINT_H_ */