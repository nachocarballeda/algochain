#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <fstream>
#include <string>
#include <sstream>
#include "../include/body.h"
#include "../include/header.h"
#include "../include/txn.h"
#include "../include/input.h"
#include "../include/output.h"

class Block
{
public:
    Block();
    Block(const string);
    void loadTxns(const string);
    void print();

private:
    Header _header;
    Body _body;
};

#endif /** _BLOCK_H_ */