#ifndef _MERKLE_H_
#define _MERKLE_H_
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../include/algovector.h"
#include "../include/error.h"

using namespace std;

const string merkleHash(algoVector<string> s)
{

    while (s.size() > 1)
    {
        algoVector<string> calulatedHashes;
        if (s.size() % 2 != 0)
        {
            s.push_back(s.back());
        }
        for (size_t i = 0; i < s.size() - 1; i = i + 2)
        {
            string aux;
            cout << "i = " << i << endl;
            aux.append(s[i]);
            aux.append(s[i + 1]);
            calulatedHashes.push_back(aux);
        }
        s = calulatedHashes;
    }
    return s[0];
}
