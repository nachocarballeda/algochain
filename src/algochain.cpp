#include "../include/algovector.h"
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

using namespace std;

std::tuple<string, float, size_t> _command_init(istringstream &user_input);
std::tuple<string> _command_balance(istringstream &user_input);
std::tuple<string, unordered_map<string, float>, float> _command_transfer(istringstream &user_input);
std::tuple<size_t> _command_mine(istringstream &user_input);
std::tuple<string> _command_txn(istringstream &user_input);
std::tuple<string> _command_block(istringstream &user_input);

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

    string genesisInputTxId(64, '0');
    string genesisInputTxAddr(64, '0');

    algoVector<Input> initInputVec;
    algoVector<Output> initOutputVec;

    Output genesisOutput(sha256(user), value);
    Input genesisInput(genesisInputTxId, genesisInputTxAddr, 0);

    initInputVec.push_back(genesisInput);
    initOutputVec.push_back(genesisOutput);

    Txn initTxn(1, initInputVec, 1, initOutputVec);

    _utxos.update(user, sha256(initTxn.cat()), initTxn);
    Body genesisBody(initTxn);
    Header genesisHeader(bits);
    Block genesisBlock(genesisHeader, genesisBody);

    _balance.update(user, value);

    _aux1 = new BlockNode(genesisBlock);
    _aux1->_data = genesisBlock;
    _aux1->_next = 0;
    _first = _aux1;
    _first->_ant = 0;
    // actualizo la memorizacion de txn y block una vez que ya se paso a la algo chain
    _blocks_memo.update(sha256(_first->getData().cat()), &_first->getData());
    _txns_memo.update(sha256(_first->getData().getBody().getTxns()[0].cat()), &(_first->getData().getBody().getTxns()[0]));
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

void Algochain::transfer(const string &src_user, const unordered_map<string, float> &destianations, const float &cum_sum)
{
    size_t dest_count = 1; // arrango en 1 para contemplar el output del src user
    string tx_id = _utxos.getUserUtxoHash(src_user);
    cout << tx_id << endl;
    int idx = _utxos.findUtxoIdx(src_user);
    cout << idx << endl;
    string addr = sha256(src_user);

    if (tx_id == "")
        cout << "User doesn't exist" << endl;
    else if (idx == -1)
    {
        cout << "ERROR FINDING IDX FOR SOURCE USER" << src_user << endl;
    }
    else
    {
        Input transferInput(tx_id, addr, idx);
        algoVector<Input> transferInputVec;
        transferInputVec.push_back(transferInput);

        algoVector<Output> transferOutputVec;

        for (const auto &n : destianations)
        {
            Output newOutput(sha256(n.first), n.second);
            transferOutputVec.push_back(newOutput);
            dest_count = dest_count + 1;
        }
        Output srcUserOutput(sha256(src_user), _balance.getUserBalance(src_user) - cum_sum);
        transferOutputVec.push_back(srcUserOutput);
        Txn new_txn(1, transferInputVec, dest_count, transferOutputVec);

        unordered_map<string, float> newBalance = destianations;
        newBalance.insert({src_user, _balance.getUserBalance(src_user) - cum_sum});
        Balance mempoolBalance(newBalance);
        _mempool.setNewBalance(mempoolBalance);
        _mempool.addTxn(new_txn);
    }
}

void Algochain ::mine(const size_t &bits)
{
    Body newBody(_mempool.getNewTxns());
    Header newHeader(bits);
    _balance = _mempool.getNewBalance();
    Block newBlock(newHeader, newBody);
    newBlock.updateTxnsHash();

    _blocks_memo.update(sha256(newBlock.cat()), &newBlock);
    for (size_t i = 0; i < newBody.getTxns().size(); i++)
        _txns_memo.update(sha256(newBody.getTxns()[i].cat()), &newBody.getTxns()[i]);

    this->addBlock(newBlock);
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

const Mempool &Algochain::getMempool()
{
    return _mempool;
}

const TxnsMemo &Algochain::getTxnsMemo()
{
    return _txns_memo;
}

const BlocksMemo &Algochain::getBlocksMemo()
{

    return _blocks_memo;
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
        {
            string src_user;
            unordered_map<string, float> dest;
            float cum_sum;
            if (algochain.isEmpty())
                cout << MSG_INIT_ALGOCHAIN_FIRST << endl;
            else
            {
                tie(src_user, dest, cum_sum) = _command_transfer(user_input);
                if (cum_sum == -1 || algochain.getBalance().getUserBalance(src_user) < cum_sum)
                    cout << "Invalid transfer" << endl;
                else
                {
                    algochain.transfer(src_user, dest, cum_sum);
                }
            }
        }

        else if (user_command == COMMAND_MINE)
            if (algochain.isEmpty())
                cout << MSG_INIT_ALGOCHAIN_FIRST << endl;
            else
            {
                tie(bits) = _command_mine(user_input);
                if (algochain.getMempool().getNewTxns().empty())
                    cout << "There are no Txns to mine" << endl;
                else
                {
                    algochain.mine(bits);
                }
            }

        else if (user_command == COMMAND_BALANCE)
            if (algochain.isEmpty())
                cout
                    << MSG_INIT_ALGOCHAIN_FIRST << endl;
            else
            {
                tie(user_name) = _command_balance(user_input);
                float userBalance = algochain.getBalance().getUserBalance(user_name);
                cout << userBalance << endl;
            }

        else if (user_command == COMMAND_BLOCK)
            if (algochain.isEmpty())
                cout
                    << MSG_INIT_ALGOCHAIN_FIRST << endl;
            else
            {
                string block_hash;
                tie(block_hash) = _command_block(user_input);
                if (block_hash == "")
                    ;

                else
                {
                    Block *block = algochain.getBlocksMemo().getData().at(block_hash);
                    cout << block->cat() << endl;
                }
            }
        else if (user_command == COMMAND_TXN)
            if (algochain.isEmpty())
                cout
                    << MSG_INIT_ALGOCHAIN_FIRST << endl;
            else
            {
                string txn_hash;
                tie(txn_hash) = _command_txn(user_input);
                if (txn_hash == "")
                    ;

                else
                {
                    cout << algochain.getTxnsMemo().getData().at(txn_hash)->cat() << endl;
                }
            }

        else if (user_command == COMMAND_LOAD)
            if (algochain.isEmpty())
                cout
                    << MSG_INIT_ALGOCHAIN_FIRST << endl;
            else
                cout << "loading from file.." << endl;

        else if (user_command == COMMAND_SAVE)
            if (algochain.isEmpty())
                cout
                    << MSG_INIT_ALGOCHAIN_FIRST << endl;
            else
                cout << "saving to file..";

        else if (user_command == COMMAND_HELP)
            cout << COMMAND_REPLY_TO_HELP << endl;

        else if (user_command == COMMAND_EXIT)
        {
            cout << "bye.." << endl;
            exit(0);
        }
        else
            cout << "Command is invalid. Write help to see all the available commands" << endl;
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
    if (bits <= 0)
    {
        cout << "Please, insert a valid number of bits" << endl;
    }
    else if (value <= 0)
    {
        cout << "Invalid number of Algocoins" << endl;
    }
    else if (user_input.fail())
    {
        cout << "Initialization fail" << endl;
    }
    else
    {
        return std::make_tuple(user_name, value, bits);
    }
}

std::tuple<string> _command_balance(istringstream &user_input)
{
    string user_name;
    user_input >> user_name;
    return std::make_tuple(user_name);
}

std::tuple<size_t> _command_mine(istringstream &user_input)
{
    size_t bits;
    user_input >> bits;
    if (user_input.fail() || bits <= 0)
    {
        cout << "Please, insert a valid number of bits" << endl;
    }
    else
    {
        return std::make_tuple(bits);
    }
}

//Devuelve el nombre del source, un diccionario con los nombres y
//valores para el destino y un float con la suma acumulada de lo que se tiene que transferir

std::tuple<string, unordered_map<string, float>, float> _command_transfer(istringstream &user_input)
{
    string src_user;
    user_input >> src_user;
    unordered_map<string, float> dest;
    float cum_sum = 0;
    while (!user_input.eof())
    {
        string user_name;
        float value;
        user_input >> user_name;
        user_input >> value;
        cum_sum = cum_sum + value;
        dest.insert({user_name, value});
        if (user_input.fail())
        {
            dest.clear();
            src_user = "";
            cum_sum = -1;
            return std::make_tuple(src_user, dest, cum_sum);
        }
    }
    return std::make_tuple(src_user, dest, cum_sum);
}

std::tuple<string> _command_txn(istringstream &user_input)
{
    string txn_hash;
    user_input >> txn_hash;
    if (txn_hash.length() != 64)
    {
        cout << "Invalid Txn Hash" << endl;
        return std::make_tuple("");
    }
    return std::make_tuple(txn_hash);
}

std::tuple<string> _command_block(istringstream &user_input)
{
    string block_hash;
    user_input >> block_hash;
    if (block_hash.length() != 64)
    {
        cout << "Invalid Txn Hash" << endl;
        return std::make_tuple("");
    }
    return std::make_tuple(block_hash);
}
