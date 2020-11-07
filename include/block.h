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
private:
    Header _header;
    Body _body;

public:
    Block();
    Block(const Header &, const Body &);
    Block(const Block &);
    Block(const string);
    ~Block();

    void setHeader(const Header &);
    void setBody(const Body &);
    Header const &getHeader() const;
    Body const &getBody() const;
    void updateTxnsHash();
    

    void loadTxns(const string);
    void writeToFile(const string);
    void print();

    friend std::ostream &operator<<(std::ostream &, const Block &);

private:
    void proofOfWork();
};

#endif /** _BLOCK_H_ */