#ifndef _OUTPUTS_H_
#define _OUTPUTS_H_

#include <cstdlib>
#include <vector>
using namespace std;

class Output
{
public:
    Output();
    Output(vector<char> &, size_t);
    const vector<char> &get_addr();
    const size_t &get_value();

private:
    static const size_t ADDR_MAX_SIZE = 32;
    vector<char> addr;
    size_t value;
};

#endif /** _OUTPUTS_H_ */