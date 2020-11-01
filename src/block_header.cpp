#include "../include/block_header.h"

#include <iostream>

BlockHeader::BlockHeader(void)
{
    std::cout << "Header Constructor was called." << std::endl;
}

char* BlockHeader::getPrevBlock(void)
{
    return prev_block;
}