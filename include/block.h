#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "../include/block_body.h"
#include "../include/block_header.h"

class Block
{
    public:
        Block();
    private:
        BlockHeader _header;
        BlockBody _body;
};

#endif /** _BLOCK_H_ */