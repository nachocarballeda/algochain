#ifndef _BLOCKS_MEMO_H_
#define _BLOCKS_MEMO_H_

#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include "../include/output.h"
#include "../include/input.h"
#include "../include/outpoint.h"
#include "../include/txn.h"
#include "../include/block.h"

using namespace std;

class BlocksMemo
{
public:
    BlocksMemo();
    ~BlocksMemo();
    const unordered_map<string, Block *> &getData() const;

    const bool isEmpty();

    void clear();
    void update(const string &, Block *);

private:
    unordered_map<string, Block *> _data;
};

#endif /** _BLOCKS_MEMO_H_ */