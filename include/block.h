#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "../include/body.h"
#include "../include/header.h"

class Block
{
    public:
        Block();
    private:
        Header _header;
        Body _body;
};

#endif /** _BLOCK_H_ */