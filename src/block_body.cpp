#include "../include/block_body.h"

#include <iostream>

BlockBody::BlockBody(void)
{
    std::cout << "Body Constructor was called." << std::endl;
}

size_t BlockBody::getTxnCount(void)
{
    return txn_count;
}
