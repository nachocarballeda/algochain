#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "../include/body.h"
#include "../include/header.h"

class Block
{
    private:
        Header _header;
        Body _body;

    public:
        Block();
        Block(const Header &, const Body &);
        Block(const Block &);
        ~Block();

        void setHeader(const Header &);
        void setBody(const Body &);
        Header const &getHeader() const;
        Body const &getBody() const;
        void updateTxnsHash();
        void proofOfWork();


        friend std::ostream &operator<<(std::ostream &, const Block &);

    
};

#endif /** _BLOCK_H_ */