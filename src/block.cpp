#include "../include/block.h"
#include "../include/body.h"
#include "../include/sha256.h"
#include "../include/errorlog.h"
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

Block::Block()
{
}

Block::Block(const Header &h, const Body &b)
{
    _header = h;
    _body = b;
}

Block::Block(const Block &b)
{
    _header = b._header;
    _body = b._body;
}

Block::~Block()
{
}

Block::Block(string filepath)
{
    loadTxn(filepath);
}

void Block::loadTxn(const string filepath)
{
    ifstream txns_file(filepath);
    Txn newTxn;
    if (!txns_file.good())
    {
        showError(MSG_ERROR_INVALID_FILEPATH);
        return;
    }

    while (!txns_file.eof())
    {
        string line;
        int n_tx_in = 0;
        int n_tx_out = 0;
        getline(txns_file, line);
        istringstream inputStream(line);
        if (line.length() == 0)
            return;
        inputStream >> n_tx_in;
        if (n_tx_in < 1)
        {
            showError(MSG_ERROR_INVALID_N_TX_IN);
            return;
        }

        for (int i = 0; i < n_tx_in; ++i)
        {
            getline(txns_file, line);
            istringstream input_data(line);
            string tx_id;
            int id_x;
            string addr;
            input_data >> tx_id;
            if (tx_id.length() != 64 || input_data.fail())
            {
                showError(MSG_ERROR_INVALID_TX_ID, "Input number " + (i + 1));
                return;
            }
            input_data >> id_x;
            if (id_x < 0 || input_data.fail())
            {
                showError(MSG_ERROR_INVALID_IDX, "Input number " + (i + 1));
                return;
            }
            input_data >> addr;
            if (addr.length() != 64 || input_data.fail())
            {
                showError(MSG_ERROR_INVALID_ADDR, "Input number " + (i + 1));
                return;
            }
            Input newInput(addr, tx_id, id_x);
            newTxn.addInput(newInput);
        }

        getline(txns_file, line);
        istringstream outputStream(line);
        outputStream >> n_tx_out;
        if (n_tx_out > n_tx_in || outputStream.fail())
        {
            showError(MSG_ERROR_INVALID_N_TX_OUT);
            return;
        }
        for (int i = 0; i < n_tx_out; ++i)
        {

            getline(txns_file, line);
            istringstream output_data(line);
            float value;
            string addr;
            output_data >> value;
            if (value < 0 || output_data.fail())
            {
                showError(MSG_ERROR_INVALID_OUTPUT_VALUE, "Output number " + (i + 1));
                return;
            }
            output_data >> addr;
            if (addr.length() != 64 || output_data.fail())
            {
                showError(MSG_ERROR_INVALID_OUTPUT_ADDR, "Output number " + (i + 1));
                return;
            }
            Output newOutput(addr, value);
            newTxn.addOutput(newOutput);
        }

        _body.addTxn(newTxn);
    }
    txns_file.close();
}

void Block::print()
{
    cout << _header.cat() << endl;
    cout << _body.cat() << endl;
}

void Block::writeToFile(string filepath)
{
    if(filepath[0]!='-')
    {
        ofstream block_file(filepath);
        if (!block_file.good())
        {
            showError(MSG_ERROR_INVALID_FILEPATH);
            return;
        }
        block_file << _header.cat()
                << _body.cat();

        if (!block_file.good())
        {
            showError(MSG_ERROR_WRITING_TO_FILE);
            return;
        }
        block_file.close();
    }
    else
    {
        cout << _header.cat()
             << _body.cat();
    }
}

void Block::setHeader(const Header &h)
{
    _header = h;
}

void Block::setBody(const Body &b)
{
    _body = b;
}

void Block::setDifficulty(const size_t &d)
{
    _header.setBits(d);
}

Header const &Block::getHeader() const
{
    return _header;
}

Body const &Block::getBody() const
{
    return _body;
}

void Block::updateTxnsHash()
{

    string s = _body.cat();
    _header.setTxnsHash(sha256(sha256(s)));

    proofOfWork();
}

void Block::proofOfWork()
{

    size_t d = _header.getBits(); //Obtengo la dificultad

    if (d == 0) //Si es 0, es indistinto el hash.
        return;

    size_t count = 0;
    bitset<4> c;
    bool _minning = true;

    while (_minning)
    {

        string s = _header.cat();

        string h = sha256(sha256(s));

        for (size_t j = 0; j < 32; j++)
        { //Reviso los 32 bytes del hash.

            if ((h[j] - 48) > 48)   //Si esta entre a-f
                c = (h[j] - 87);
            else                    //Si esta entre 0-9
                c = (h[j] - 48);

            size_t i = 0;

            /*
                Pruebo que cada bit sea 0. El bit c[0] = LSb y c[3] = MSb
            */
            for ( ;i < 4; i++)
            {
                if (c[3 - i] != 0)
                    break;
                count++;
            }

            if (i == 0)
            {
                _header.incrementNonce();
                count = 0;
                break;
            }

            if ((count < d) && ((count % 4) != 0))
            {
                _header.incrementNonce();
                count = 0;
                break;
            }

            if (count >= d)
            { //Si el count es mayor o igual a la dificultad
                _minning = false;
                break; //Salgo del ciclo.
            }
        }
    }
}

ostream &operator<<(ostream &os, Block b)
{
    return os << b._header
              << b._body;
}
