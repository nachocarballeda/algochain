#ifndef _OUTPUTS_H_
#define _OUTPUTS_H_

#include <cstdlib>
#include <string>
using namespace std;

class Output
{
public:
    Output();
    Output(string, float);
    string getAddr();
    size_t getValue();

private:
    string addr;
    float value;
};

#endif /** _OUTPUTS_H_ */