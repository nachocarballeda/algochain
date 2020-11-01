#include "../include/header.h"

#include <iostream>

using namespace std;

Header::Header(void)
{
    cout << "Header Constructor was called." << endl;
}

char* Header::getPrevBlock(void)
{
    return _prev_block;
}