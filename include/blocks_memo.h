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
    const unordered_map<string, const Block *> &getData() const;

    const bool isEmpty() const;

    void clear();
    void update(const string &, const Block *);

private:
    unordered_map<string, const Block *> _data;
};

#endif /** _BLOCKS_MEMO_H_ */