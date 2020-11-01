#include "../include/block_header.h"

#include <iostream>

using namespace std;

BlockHeader::BlockHeader(void)
{
    cout << "Header Constructor was called." << endl;
}

char* BlockHeader::getPrevBlock(void)
{
    return _prev_block;
}