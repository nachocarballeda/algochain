#ifndef _MERKLE_H_
#define _MERKLE_H_
#include <fstream>
#include <string>
#include <sstream>
#include "../include/algovector.h"
#include "../include/errorlog.h"
#include "../include/sha256.h"

const string merkleHash(algoVector<string> s)
{
    algoVector<string> calulatedHashes;
    string aux;
    while (s.size() > 1)
    {
        if (s.size() % 2 != 0)
        {
            s.push_back(s.back());
        }
        for (size_t i = 0; i < s.size(); i = i + 2)
        {
            aux = s[i] + s[i + 1];
            calulatedHashes[i / 2] = sha256(aux);
        }
        s = calulatedHashes;
    }
    return s[0];
}

#endif