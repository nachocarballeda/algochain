#include "../include/txns.h"
#include "../include/outputs.h"
#include "../include/inputs.h"

#include <iostream>

using namespace std;

Txns::Txns()
{
    cout << "Txns Constructor was called." << endl;
    Inputs input0; //Just testing inputs/outputs Constructors
    Outputs output0;
    _inputs.push_back(input0);
    _outputs.push_back(output0);
}