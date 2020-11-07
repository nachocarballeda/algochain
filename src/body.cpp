#include "../include/body.h"
#include "../include/txn.h"

#include <iostream>
#include <vector>

using namespace std;

Body::Body(void)
{
    cout << "Body Constructor was called." << endl;
    _txn_count = 0;
}

void Body::setTxnCount(size_t txn_count)
{
    _txn_count = txn_count;
}

size_t Body::getTxnCount(void)
{
    return _txn_count;
}

void Body::addTxn(Txn newTxn)
{
    _txns.push_back(newTxn);
    _txn_count = _txn_count + 1;
}

string Body::generateTxnsHash()
{
    string concatTxns = "";
    cout << _txns[0].getNTxIn() << endl;
    cout << _txns[0].getNTxOut() << endl;
    for (size_t i = 0; i < _txn_count; i++)
    {
        concatTxns.append(to_string(_txns[i].getNTxIn()));
        concatTxns.append("\n");

        for (size_t j = 0; j < _txns[i].getNTxIn(); ++j)
        {
            concatTxns.append((_txns[i].getInputs())[j].getAddr());
            concatTxns.append(" ");
            concatTxns.append(to_string((_txns[i].getInputs())[j].getOutpointIdx()));
            concatTxns.append(" ");
            concatTxns.append((_txns[i].getInputs())[j].getOutpointTxId());
            concatTxns.append("\n");
        }
        concatTxns.append(to_string(_txns[i].getNTxOut()));
        concatTxns.append("\n");
        for (size_t j = 0; j < _txns[i].getNTxOut(); ++j)
        {
            concatTxns.append(to_string((_txns[i].getOutputs())[j].getValue()));
            concatTxns.append(" ");
            concatTxns.append((_txns[i].getOutputs())[j].getAddr());
            concatTxns.append("\n");
        }
    }
    cout << "TXNS HASH:" << sha256(concatTxns) << endl;
    return sha256(concatTxns);
}

void Body::print()
{
    string concatTxns = "";
    for (size_t i = 0; i < _txn_count; i++)
    {
        concatTxns.append("\n+++++ TX ");
        concatTxns.append(to_string(_txn_count));
        concatTxns.append("+++++\n");
        concatTxns.append("<<<INPUTS>>>\n");
        concatTxns.append(to_string(_txns[i].getNTxIn()));
        concatTxns.append("\n");
        for (size_t j = 0; j < _txns[i].getNTxIn(); ++j)
        {
            concatTxns.append((_txns[i].getInputs())[j].getAddr());
            concatTxns.append(" ");
            concatTxns.append(to_string((_txns[i].getInputs())[j].getOutpointIdx()));
            concatTxns.append(" ");
            concatTxns.append((_txns[i].getInputs())[j].getOutpointTxId());
            concatTxns.append("\n");
        }
        concatTxns.append("<<<OUTPUTS>>>\n");
        concatTxns.append(to_string(_txns[i].getNTxOut()));
        concatTxns.append("\n");

        for (size_t j = 0; j < _txns[i].getNTxOut(); ++j)
        {
            concatTxns.append(to_string((_txns[i].getOutputs())[j].getValue()));
            concatTxns.append(" ");
            concatTxns.append((_txns[i].getOutputs())[j].getAddr());
            if (j != _txns[i].getNTxOut() - 1)
                concatTxns.append("\n");
        }
    }

    cout << "============  BODY  ============" << endl
         << "TRANSACTIONS COUNT: " << _txn_count << endl
         << "TRANSACCIONES: " << concatTxns << endl;
}