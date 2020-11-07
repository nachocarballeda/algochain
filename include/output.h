#ifndef _OUTPUTS_H_
#define _OUTPUTS_H_

#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

class Output
{
public:
    Output();
    Output(string, size_t);
    string getAddr();
    size_t getValue();

private:
    string addr;
    size_t value;
};

#endif /** _OUTPUTS_H_ */