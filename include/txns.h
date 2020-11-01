#ifndef _TXNS_H_
#define _TXNS_H_

#include <cstdlib>
#include <vector>

#include "../include/outputs.h"
#include "../include/inputs.h"

using namespace std;

class Txns
{
    public:
        Txns();
    private:
        size_t _n_tx_in;
        vector<Inputs> _inputs;
        size_t _n_tx_out;
        vector<Outputs> _outputs;
};

#endif /** _TXNS_H_ */