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
#include <tuple>

std::tuple<string, float, size_t> _command_init(istringstream &user_input);
std::tuple<string> _command_balance(istringstream &user_input);

Algochain ::Algochain()
{
    _first = 0;
}

void Algochain::init(string user, float value, size_t bits)
{
    if (this->isEmpty())
    {
    }
    else
    {
        _balance.clear();
        BlockNode *_aux = _first;
        while (_first)
        {
            _first = _first->_next;
            delete _aux;
            _aux = _first;
        }
        _first = 0;
    }

    BlockNode *_aux1;
    vector<Input> initInputVec;
    vector<Output> initOutputVect;
    Output genesisOutput(sha256(user), value);
    initOutputVect.push_back(genesisOutput);
    Txn initTxn(0, initInputVec, 1, initOutputVect);
    Body genesisBody(initTxn);
    Header genesisHeader(bits);
    Block genesisBlock(genesisHeader, genesisBody);

    _balance.update(user, value);

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

void Algochain ::emit()
{
    BlockNode *aux = _first;
    while (aux)
    {
        cout << aux->getData() << endl;
        aux = aux->getNext();
    }
}

string Algochain ::getGenesisBlockHash()
{
    if (isEmpty())
    {
        showError(MSG_ERROR_EMPTY_ALGOCHAIN);
    }
    ostringstream oss;
    oss << _first->getData();
    return sha256(oss.str());
}

bool Algochain ::isEmpty() const
{
    return (_first == 0);
}

void algochainStart(void)
{
    istringstream user_input;
    string user_command;
    string user_complete_line;

    Algochain algochain;
    string user_name;
    float value;
    size_t bits;

    while (true)
    {
        getline(cin, user_complete_line);
        istringstream user_input(user_complete_line);
        user_input >> user_command;
        if (user_command == COMMAND_INIT)
        {
            tie(user_name, value, bits) = _command_init(user_input);
            algochain.init(user_name, value, bits);
            cout << algochain.getGenesisBlockHash() << endl;
        }
        else if (user_command == COMMAND_TRANSFER)
            if (algochain.isEmpty())
                cout << MSG_INIT_ALGOCHAIN_FIRST << endl;
            else
                cout << "transfer done.." << endl;

        else if (user_command == COMMAND_MINE)
            if (algochain.isEmpty())
                cout << MSG_INIT_ALGOCHAIN_FIRST << endl;
            else
                cout << "minning start !" << endl;

        else if (user_command == COMMAND_BALANCE)
            if (algochain.isEmpty())
                cout << MSG_INIT_ALGOCHAIN_FIRST << endl;
            else
            {
                tie(user_name) = _command_balance(user_input);
                float userBalance = algochain.getBalance().getUserBalance(user_name);
                cout << userBalance << endl;
            }

        else if (user_command == COMMAND_BLOCK)
            if (algochain.isEmpty())
                cout << MSG_INIT_ALGOCHAIN_FIRST << endl;
            else
                cout << "block's fields are.." << endl;

        else if (user_command == COMMAND_TXN)
            if (algochain.isEmpty())
                cout << MSG_INIT_ALGOCHAIN_FIRST << endl;
            else
                cout << "txn command.." << endl;

        else if (user_command == COMMAND_LOAD)
            if (algochain.isEmpty())
                cout << MSG_INIT_ALGOCHAIN_FIRST << endl;
            else
                cout << "loading from file.." << endl;

        else if (user_command == COMMAND_SAVE)
            if (algochain.isEmpty())
                cout << MSG_INIT_ALGOCHAIN_FIRST << endl;
            else
                cout << "saving to file..";

        else if (user_command == COMMAND_HELP)
            if (algochain.isEmpty())
                cout << MSG_INIT_ALGOCHAIN_FIRST << endl;
            else
                cout << "display help file.." << endl;

        else if (user_command == COMMAND_EXIT)
        {
            cout << "bye.." << endl;
            exit(0);
        }
        else
        {
            cout << "Command is invalid. Write help to see all the available commands" << endl;
        }
    }
}

const Balance Algochain::getBalance() const
{
    return _balance;
}

void Algochain::emitBalance()
{
    cout << _balance;
}

std::tuple<string, float, size_t> _command_init(istringstream &user_input)
{
    string user_name;
    float value;
    size_t bits;
    user_input >> user_name;
    user_input >> value;
    user_input >> bits;
    return std::make_tuple(user_name, value, bits);
}

std::tuple<string> _command_balance(istringstream &user_input)
{
    string user_name;
    user_input >> user_name;
    return std::make_tuple(user_name);
}