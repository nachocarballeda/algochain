#include "../include/header.h"

#include <iostream>

using namespace std;

Header::Header()
{
    _bits = 0;
    _txns_hash = "";
}

Header::Header(size_t &b)
{
    _bits = b;
    _txns_hash = "";
}

Header::Header(const Header &h)
{
    _bits = h._bits;
    _txns_hash = h._txns_hash; 
    _nonce = h._nonce;
    _prev_block = h._prev_block;
}

Header const & Header::operator=(Header const &r){

    _bits = r._bits;
    _txns_hash = r._txns_hash;
    _prev_block = r._prev_block;
    _nonce = r._nonce;
    return *this;
}

Header::~Header()
{
}

string const & Header::getPrevBlock() const
{
    return _prev_block;
}

size_t const & Header::getBits() const
{
    return _bits;
}

size_t const & Header::getNonce() const{
    return _nonce;
}

string const & Header::getTxnsHash() const{
    return _txns_hash;
}


void Header::setBits(size_t const &b){
    _bits = b;
}

void Header::setTxnsHash(string const &s){
    _txns_hash = s;
}

void Header::incrementNonce(){
    _nonce++;
}

string Header::cat(){

    string s;

    s += _prev_block;
    s += '\n';
    s += _txns_hash;
    s += '\n';
    s += to_string(_bits);
    s += '\n';
    s += to_string(_nonce);
    s += '\n';

    return s;

}

ostream &operator<<(ostream &os, const Header &h){
    return os << h._prev_block << endl
	          << h._txns_hash << endl
	          << h._bits << endl 
	          << h._nonce << endl;
}