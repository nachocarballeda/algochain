#include "../include/block.h"

#include <iostream>

using namespace std;

Block::Block()
{
    cout << "Block Constructor was called." << endl;
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