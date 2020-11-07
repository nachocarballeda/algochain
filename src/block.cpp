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

    while (!txns_file.eof())
    {
        string line;
        size_t n_tx_in = 0;
        size_t n_tx_out = 0;
        getline(txns_file, line);
        istringstream inputStream(line);

        inputStream >> n_tx_in;
        // cout << "N TX IN: " << n_tx_in << endl;

        for (size_t i = 0; i < n_tx_in; ++i)
        {

            getline(txns_file, line);
            istringstream input_data(line);
            string tx_id;
            size_t id_x;
            string addr;
            input_data >> tx_id;
            input_data >> id_x;
            input_data >> addr;
            Input newInput(addr, tx_id, id_x);
            newTxn.addInput(newInput);
            // cout << "TX ID: " << tx_id << endl
            //      << "ID X: " << id_x << endl
            //      << "ADDR: " << addr << endl;
        }

        getline(txns_file, line);
        istringstream outputStream(line);
        outputStream >> n_tx_out;

        for (size_t i = 0; i < n_tx_out; ++i)
        {

            getline(txns_file, line);
            istringstream output_data(line);
            float value;
            string addr;
            output_data >> value;
            output_data >> addr;
            Output newOutput(addr, value);
            newTxn.addOutput(newOutput);
            // cout << "VALUE: " << value << endl
            //      << "ADDR: " << addr << endl;
        }

        _body.addTxn(newTxn);

        cout << "Transactions loaded" << endl;
    }
}

void Block::print()
{
    _body.print();
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
    //Falta funcion para concatenar las transacciones.

    /*
    
    
    string s = _body.concatenacion();
    _header.setTxnsHash(sha256(sha256(s)));

    //aqui va el proofofwork, no en el main.

    //funcion de prueba
    cout << _header.getTxnsHash() << endl;
    */

    cout << "Falta Implementar la concantenacion de las transacciones." << endl;
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

            // cout << "byte = " << c << endl;

            size_t i = 0;

            /*
                Pruebo que cada bit sea 0. El bit c[0] = LSb y c[3] = MSb
            */
            for (; i < 4; i++)
            {

                if (c[3 - i] != 0)
                {
                    // cout << "i" << i << endl;
                    break;
                }

                conteo++;
                // cout << "adentro" << conteo << endl;
            }

            if (i == 0)
            {
                _header.incrementNonce();
                conteo = 0;
                // cout << "IGual a 0" << endl;
                break;
            }

            if ((conteo < d) && ((conteo % 4) != 0))
            {
                _header.incrementNonce();
                // cout << conteo << "menor" << endl;
                conteo = 0;
                break;
            }

            if (conteo >= d)
            { //Si el conteo es mayor o igual a la dificultad
                flag = false;
                //cout << conteo << "sali" << endl;
                break; //Salgo del ciclo.
            }

            // cout << "Conteo afuera" << conteo << endl;
        }
    }
}

ostream &operator<<(ostream &os, const Block &b)
{
    return os << b._header;
    // << b._body            FALTA IMPLEMENTAR ESTA FUNCION
}
