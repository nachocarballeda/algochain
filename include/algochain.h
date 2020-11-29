#ifndef _ALGOCHAIN_H_
#define _ALGOCHAIN_H_
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <queue>
#include "../include/algovector.h"
#include "../include/error.h"
#include "../include/body.h"
#include "../include/block.h"
#include "../include/header.h"
#include "../include/txn.h"
#include "../include/input.h"
#include "../include/output.h"
#include "../include/balance.h"
#include "../include/utxos.h"
#include "../include/mempool.h"
#include "../include/txns_memo.h"
#include "../include/blocks_memo.h"

#define MSG_INIT_ALGOCHAIN_FIRST "Please init the Algochain first"

#define COMMAND_INIT "init"
#define COMMAND_BALANCE "balance"
#define COMMAND_MINE "mine"
#define COMMAND_TRANSFER "transfer"
#define COMMAND_BLOCK "block"
#define COMMAND_TXN "txn"
#define COMMAND_LOAD "load"
#define COMMAND_SAVE "save"
#define COMMAND_HELP "help"
#define COMMAND_EXIT "exit"
#define COMMAND_REPLY_TO_HELP "\
    init <user> <value> <bits>\n\
    transfer <src> <dst1> <value1> ... <dstN> <valueN>\n\
    mine <bits>\n\
    balance <user>\n\
    block <id>\n\
    txn <id>\n\
    load <filename>\n\
    save <filename>\n"

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
    Block &getData() { return _data; }
    BlockNode *getNext() { return _next; }

private:
    Block _data;
    BlockNode *_next, *_ant;
};

class Algochain
{
public:
    Algochain();
    ~Algochain();
    void init(string, float, size_t);
    const Balance getBalance() const;
    const TxnsMemo &getTxnsMemo();
    const BlocksMemo &getBlocksMemo();
    const Mempool &getMempool();
    string getGenesisBlockHash();

    void transfer(const string &, const unordered_map<string, float> &, const float &);
    void mine(const size_t &bits);
    void addBlock(Block &);            //alta al final
    void updateBalance(string, float); //actualizar balance de usuarios
    void emitBalance();
    void emit(); //emite la lista. Escribirla

    bool isEmpty() const; //retorna true si lista vacia

private:
    BlockNode *_first;
    Balance _balance;
    Utxos _utxos;
    TxnsMemo _txns_memo;
    BlocksMemo _blocks_memo;
    Mempool _mempool;
};

void algochainStart(void);

#endif