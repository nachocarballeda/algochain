#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <tuple>
#include <unordered_map>

#include "include/algochain.h"
#include "include/body.h"
#include "include/header.h"
#include "include/block.h"
#include "include/sha256.h"
#include "include/cmdline.h"
#include "include/errorlog.h"
#include "include/arghandler.h"

option_t options[] = {
    {1, "d", "difficulty", "1", opt_set_difficulty, OPT_MANDATORY},
    {1, "o", "output", "-", opt_set_output, OPT_DEFAULT},
    {1, "i", "input", "-", opt_set_input, OPT_DEFAULT},
    {
        0,
    }};

using namespace std;

int main(int argc, char *argv[])
{
    // TP 0

    // string _input_file;
    // string _output_file;
    // size_t _difficulty;
    // cmdline cmdl(options);
    // cmdl.parse(argc, argv);
    // tie(_input_file, _output_file, _difficulty) = opt_get_values();
    // Block block0(_input_file);
    // block0.setDifficulty(_difficulty);
    // block0.updateTxnsHash();
    // block0.writeToFile(_output_file);

    istringstream user_input;
    string user_command;
    string user_complete_line;

    while(true)
    {
        getline(cin, user_complete_line);
        istringstream user_input(user_complete_line);
        user_input >> user_command;
        cout << "comando es " << user_command << endl;
        if (user_command == "init")
            cout <<  "init done.." << endl;
        else if (user_command == "transfer")
            cout << "transfer done.." << endl;
        else if (user_command == "mine")
            cout << "Minning start !" << endl;
        else if (user_command == "balance")
            cout << "balance of the user is X" << endl;
        else if (user_command == "block")
            cout << "block's fields are..." << endl;
        else if (user_command == "exit")
        {
            cout << "bye.." << endl;
            exit(0);
        }
        else
        {
            cout << "command is invalid." << endl;
        }

    }

    //TP 1
    float value = 10;
    string user = "matilareo";
    size_t bits = 2;

    Algochain algochain(value, user, bits);
    algochain.emit();
    algochain.getGenesisBlockHash();

    // Hash map para balance (EJEMPLO)

    unordered_map<string, float> balance;

    balance.insert({user, value});

    for (auto const &pair : balance)
    {
        std::cout << endl
                  << "{" << pair.first << ": " << pair.second << "}\n";
    }
}
