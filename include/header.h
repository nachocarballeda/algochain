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
    size_t _nonce = 0;

public:
    Header();                                //Constructor simple.
    Header(const size_t &);                  //Constructor con _bits.
    Header(const Header &);                  //Constructor copia.
    Header const &operator=(Header const &); //Operador '='.
    ~Header();                               //Destructor.

    string const &getPrevBlock() const; //Devuelve _prev_block.
    size_t const &getBits() const;      //Devuelve _bits.
    size_t const &getNonce() const;     //Devuelve _nonce.
    string const &getTxnsHash() const;  //Devuelve _txns_hash.
    void setBits(size_t const &);       //Establece _bits.
    void setTxnsHash(string const &);   //Establece _txns_hash.
    void incrementNonce();              //Aumenta el valor del _nonce.
    const string cat() const;           //Concatena el contenido del Header.

    friend ostream &operator<<(ostream &, Header); //Operador '<<'.
};

#endif /** _HEADER_H_ */