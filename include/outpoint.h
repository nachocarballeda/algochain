#ifndef _OUTPOINT_H_
#define _OUTPOINT_H_

#include <cstdlib>
#include <string>
using namespace std;

class Outpoint
{
public:
    Outpoint();
    Outpoint(string, size_t);
    string getTxId();
    size_t getIdx();

private:
    string tx_id;
    size_t idx;
};

#endif /** _OUTPOINT_H_ */