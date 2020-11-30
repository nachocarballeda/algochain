#ifndef _OUTPUTS_H_
#define _OUTPUTS_H_

#include <cstdlib>
#include <string>
using namespace std;

class Output
{
public:
    Output();
    Output(string, double);
    ~Output();
    string getAddr();
    double getValue();

private:
    string addr;
    double value;
};

#endif /** _OUTPUTS_H_ */