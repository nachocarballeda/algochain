#include <cstdlib>
#include <vector>
#include <unordered_map>

#include "../include/output.h"
#include "../include/input.h"
#include "../include/outpoint.h"
#include "../include/txns_memo.h"
#include "../include/blocks_memo.h"

using namespace std;

BlocksMemo::BlocksMemo()
{
}

BlocksMemo::~BlocksMemo()
{
}

const bool BlocksMemo::isEmpty() const
{
    return _data.empty();
}

void BlocksMemo::clear()
{
    _data.clear();
}
void BlocksMemo::update(const string &block_hash, const Block *block)
{

    if (_data.find(block_hash) == _data.end())
        _data.insert({block_hash, block});
    else
        _data.at(block_hash) = block;
}

const unordered_map<string, const Block *> &BlocksMemo::getData() const
{
    return _data;
}