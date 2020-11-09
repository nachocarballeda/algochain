#include "../include/block.h"
#include "../include/body.h"
#include "../include/sha256.h"

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
    ifstream txns_file(filepath);
    Txn newTxn;
    if (!txns_file.good())
    {
        cout << "ERROR_INVALID_FILEPATH" << endl;
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
        {
            cout << "TXN_FILE_IS_EMPTY" << endl;
            return;
        }
        inputStream >> n_tx_in;
        if (n_tx_in < 1)
        {
            cout << "INVALID N TX IN" << endl;
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
                cout << "INVALID TX ID IN INPUT " << i + 1 << endl;
                return;
            }
            input_data >> id_x;
            if (id_x < 0 || input_data.fail())
            {
                cout << "INVALID IDX IN INPUT " << i + 1 << endl;
                return;
            }
            input_data >> addr;
            if (addr.length() != 64 || input_data.fail())
            {
                cout << "INVALID ADDR IN INPUT " << i + 1 << endl;
                return;
            }
            Input newInput(addr, tx_id, id_x);
            newTxn.addInput(newInput);
        }

        getline(txns_file, line);
        istringstream outputStream(line);
        outputStream >> n_tx_out;
        if (n_tx_out != n_tx_in || outputStream.fail())
        {
            cout << "INVALID N TX OUT" << endl;
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
                cout << "INVALID VALUE IN OUTPUT " << i + 1 << endl;
                return;
            }
            output_data >> addr;
            if (addr.length() != 64 || output_data.fail())
            {
                cout << "INVALID ADDR IN OUTPUT " << i + 1 << endl;
                return;
            }
            Output newOutput(addr, value);
            newTxn.addOutput(newOutput);
        }

        _body.addTxn(newTxn);
    }
    txns_file.close();
}

void Block::loadTxn(const string filepath)
{
    ifstream txns_file(filepath);
    Txn newTxn;
    if (!txns_file.good())
    {
        cout << "ERROR_INVALID_FILEPATH" << endl;
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
        {
            cout << "TXN_FILE_IS_EMPTY" << endl;
            return;
        }
        inputStream >> n_tx_in;
        if (n_tx_in < 1)
        {
            cout << "INVALID N TX IN" << endl;
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
                cout << "INVALID TX ID IN INPUT " << i + 1 << endl;
                return;
            }
            input_data >> id_x;
            if (id_x < 0 || input_data.fail())
            {
                cout << "INVALID IDX IN INPUT " << i + 1 << endl;
                return;
            }
            input_data >> addr;
            if (addr.length() != 64 || input_data.fail())
            {
                cout << "INVALID ADDR IN INPUT " << i + 1 << endl;
                return;
            }
            Input newInput(addr, tx_id, id_x);
            newTxn.addInput(newInput);
        }

        getline(txns_file, line);
        istringstream outputStream(line);
        outputStream >> n_tx_out;
        if (n_tx_out < n_tx_in || outputStream.fail())
        {
            cout << "INVALID N TX OUT" << endl;
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
                cout << "INVALID VALUE IN OUTPUT " << i + 1 << endl;
                return;
            }
            output_data >> addr;
            if (addr.length() != 64 || output_data.fail())
            {
                cout << "INVALID ADDR IN OUTPUT" << i + 1 << endl;
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
    ofstream block_file(filepath);
    if (!block_file.good())
    {
        cout << "ERROR_INVALID_FILEPATH" << endl;
        return;
    }
    block_file << _header.cat()
               << _body.cat();
    if (!block_file.good())
    {
        cout << "ERROR_WRITING_TO_FILE" << endl;
        return;
    }
    block_file.close();
}

void Block::setHeader(const Header &h)
{
    _header = h;
}

void Block::setBody(const Body &b)
{
    _body = b;
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

    // cout << _header.getTxnsHash() << endl; //Prueba

    proofOfWork();
}

void Block::proofOfWork()
{

    size_t d = _header.getBits(); //Obtengo la dificultad

    if (d == 0) //Si es 0, es indistinto el hash.
        return;

    size_t conteo = 0;
    bitset<4> c;
    bool flag = true;

    while (flag)
    {

        string s = _header.cat();

        cout << s;

        string h = sha256(sha256(s));

        cout << "hash" << endl
             << h << endl;

        //La cantidad de bits nulos del hash debe ser igual o mayor a la dificultad.

        for (size_t j = 0; j < 32; j++)
        { //Reviso los 32 bytes del hash.

            if ((h[j] - 48) > 48)
            { //Si esta entre a-f

                c = (h[j] - 87);
            }
            else
            { //Si esta entre 0-9

                c = (h[j] - 48);
            }

            size_t i = 0;

            /*
                Pruebo que cada bit sea 0. El bit c[0] = LSb y c[3] = MSb
            */
            for (; i < 4; i++)
            {

                if (c[3 - i] != 0)
                {
                    break;
                }

                conteo++;
            }

            if (i == 0)
            {
                _header.incrementNonce();
                conteo = 0;
                break;
            }

            if ((conteo < d) && ((conteo % 4) != 0))
            {
                _header.incrementNonce();
                conteo = 0;
                break;
            }

            if (conteo >= d)
            { //Si el conteo es mayor o igual a la dificultad
                flag = false;
                break; //Salgo del ciclo.
            }
        }
    }
}

ostream &operator<<(ostream &os, const Block &b)
{
    return os << b._header << endl
              << b._body;
}
