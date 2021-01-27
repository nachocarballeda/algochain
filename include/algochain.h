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
#define GENESIS_BLOCK_HASH "0000000000000000000000000000000000000000000000000000000000000000"

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
    init <user> <value> <bits> \n\
            * Initialize Algochain\n\n\
    transfer <src> <dst1> <value1> ... <dstN> <valueN> \n\
            * Creates a transfer order \n\n\
    mine <bits> \n\
            * Makes a block for a given difficulty \n\n\
    balance <user> \n\
            * Prints the balance of a given user \n\n\
    block <id> \n\
            * Print block info \n\n\
    txn <id> \n\
            * Print the transaction info \n\n\
    load <filename> \n\
            * Load Algochain state from a file \n\n\
    save <filename> \n\
            * Save the Algochain state to a file \n\n\
    help \n\
            * Show this help info \n\n\
    exit \n\
            * Leaves the program without saving \n"

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
    const Block &getData() const { return _data; }
    BlockNode *getNext() const { return _next; }
    void setData(const Header &h, const Body &b)
    {
        _data.setBody(b);
        _data.setHeader(h);
    };

private:
    Block _data;
    BlockNode *_next, *_ant;
};

class Algochain
{
public:
    Algochain();
    ~Algochain();

    const Balance getBalance() const;
    const TxnsMemo &getTxnsMemo() const;
    const BlocksMemo &getBlocksMemo() const;
    const Mempool &getMempool() const;
    string getGenesisBlockHash() const;
    BlockNode *addBlock(Block _b);
    // void addBlock(Block &);
    const string getLastBlockHash() const;

    void init(string, float, size_t);
    void transfer(const string &, const unordered_map<string, float> &, const float &, bool &, ofstream &);
    void mine(const size_t &bits, bool &, ofstream &);
    //alta al final
    void updateBalance(string, float); //actualizar balance de usuarios
    void emitBalance();
    void emit(); //emite la lista. Escribirla

    void load(const string);
    const string cat() const;
    bool isEmpty() const; //retorna true si lista vacia

    friend std::ostream &operator<<(std::ostream &, Algochain);

private:
    BlockNode *_first;
    Balance _balance;
    Utxos _utxos;
    TxnsMemo _txns_memo;
    BlocksMemo _blocks_memo;
    Mempool _mempool;
};

void algochainStart(string &input_file, string &output_file);

#endif