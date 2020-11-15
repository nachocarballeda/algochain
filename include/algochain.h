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

#define COMMAND_INIT    "init"
#define COMMAND_BALANCE "balance"
#define COMMAND_MINE    "mine"
#define COMMAND_TRANSFER    "transfer"
#define COMMAND_BLOCK   "block"
#define COMMAND_TXN     "txn"
#define COMMAND_LOAD    "load"
#define COMMAND_SAVE    "save"
#define COMMAND_HELP    "help"
#define COMMAND_EXIT    "exit"


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