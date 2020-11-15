#ifndef _ALGOCHAIN_H_
#define _ALGOCHAIN_H_
#include <fstream>
#include <string>
#include <sstream>
#include "../include/error.h"
#include "../include/body.h"
#include "../include/block.h"
#include "../include/header.h"
#include "../include/txn.h"
#include "../include/input.h"
#include "../include/output.h"

class BlockNode
{
    friend class Algochain;

public:
    BlockNode(Block b)
    {
        _data = b;
        _next = 0;
        _ant = 0;
    }
    Block getData() { return _data; }
    BlockNode *getNext() { return _next; }

private:
    Block _data;
    BlockNode *_next, *_ant;
};

class Algochain
{
public:
    Algochain();
    Algochain(float, string, size_t); //constructor
    ~Algochain();                     //destructor
    void addBlock(Block);             //alta al final
    bool isEmpty() const;             //retorna true si lista vacia
    void emit();                      //emite la lista. Escribirla
    string getGenesisBlockHash();

private:
    BlockNode *_first;
};

void algochainStart(void);

#endif