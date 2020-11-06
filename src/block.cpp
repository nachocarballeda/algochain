#include "../include/block.h"
#include "../include/body.h"
#include "../include/sha256.h"

#include <iostream>
#include <string>

using namespace std;

Block::Block()
{   
}

Block::Block(const Header &h, const Body &b){
    _header = h;
    _body = b;
}

Block::Block(const Block &b){
    _header = b._header;
    _body = b._body;
}

Block::~Block()
{
}



void Block::setHeader(const Header &h){
    _header = h;
}

void Block::setBody(const Body &b){
    _body = b;
}

Header const & Block::getHeader() const{
    return _header;
}

Body const & Block::getBody() const{
    return _body;
}

void Block::updateTxnsHash(){
    //Falta funcion para concatenar las transacciones.


    /*
    
    
    string s = _body.concatenacion();
    _header.setTxnsHash(sha256(sha256(s)));

    //funcion de prueba
    cout << _header.getTxnsHash() << endl;
    */

   cout << "Falta Implementar la concantenacion de las transacciones." << endl;
}

void Block::proofOfWork(){

    string s = _header.cat();

    cout << s;

    string h = sha256(sha256(s));

    cout << h << endl;

    //Falta probar la dificultad e ir incrimentando el nonce.
}


ostream &operator<<(ostream &os, const Block &b){
    return os << b._header;
               // << b._body            FALTA IMPLEMENTAR ESTA FUNCION
}
