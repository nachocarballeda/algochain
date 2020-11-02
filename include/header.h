#ifndef _HEADER_H_
#define _HEADER_H_

#include <cstdlib>
#include <string>

using namespace std;

class Header
{
    private:
        string _prev_block = "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff";
        string _txns_hash;
        size_t _bits;
        size_t _nonce;
    public:
        Header();                               //Constructor simple.
        Header(size_t &);                       //Constructor con bits.
        Header(const Header &);                 //Constructor copia.
        ~Header();                              //Destructor.
        string getPrevBlock(void) const;        //Devuelve el _prev_block
        size_t getBits(void) const;             
        size_t getNonce(void) const;
        void setBits(size_t);
        friend std::ostream &operator<<(std::ostream &, const Header &);
    private:
        void setTxnsHash();
    
};

#endif /** _HEADER_H_ */