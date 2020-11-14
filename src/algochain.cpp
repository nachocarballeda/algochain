#include "../include/block.h"
#include "../include/body.h"
#include "../include/header.h"
#include "../include/output.h"
#include "../include/txn.h"
#include "../include/sha256.h"
#include "../include/error.h"
#include "../include/algochain.h"
#include <iostream>
#include <string>
#include <bitset>

Algochain ::Algochain(float value, string user, size_t bits)
{
    BlockNode *_aux1;

    vector<Input> initInputVec;
    vector<Output> initOutputVect;
    Output genesisOutput(sha256(user), value);
    initOutputVect.push_back(genesisOutput);
    Txn initTxn(0, initInputVec, 1, initOutputVect);
    Body genesisBody(initTxn);
    Header genesisHeader(bits);
    Block genesisBlock(genesisHeader, genesisBody);

    _aux1 = new BlockNode(genesisBlock);
    _aux1->_data = genesisBlock;
    _aux1->_next = 0;
    _first = _aux1;
    _first->_ant = 0;
}

Algochain ::~Algochain()
{
    BlockNode *_aux = _first;
    while (_first)
    {
        _first = _first->_next;
        delete _aux;
        _aux = _first;
    }
}

void Algochain ::addBlock(Block _b)
{
    BlockNode *_aux1, *_aux2;
    _aux1 = new BlockNode(_b);
    _aux1->_data = _b;
    _aux1->_next = 0;
    if (isEmpty())
    {
        _first = _aux1;
        _first->_ant = 0;
    }
    else
    {
        _aux2 = _first;
        while (_aux2->_next)
            _aux2 = _aux2->_next;
        _aux2->_next = _aux1;
        _aux1->_ant = _aux2;
    }
}

void Algochain::emit()
{
    BlockNode *aux = _first;
    while (aux)
    {
        cout << aux->getData();
        aux = aux->getNext();
    }
}

bool Algochain ::isEmpty() const
{
    return (_first == 0);
}