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
    ~Output();
    const string &getAddr() const;
    const size_t getValue() const;

private:
    string _addr;
    float _value;
};

#endif /** _OUTPUTS_H_ */