#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <tuple>
#include <unordered_map>

#include "include/algovector.h"
#include "include/algochain.h"
#include "include/body.h"
#include "include/header.h"
#include "include/block.h"
#include "include/sha256.h"
#include "include/cmdline.h"
#include "include/errorlog.h"
#include "include/arghandler.h"

option_t options[] = {
    {1, "o", "output", "-", opt_set_output, OPT_DEFAULT},
    {1, "i", "input", "-", opt_set_input, OPT_DEFAULT},
    {
        0,
    }};

using namespace std;

int main(int argc, char *argv[])
{
    string _input_file;
    string _output_file;

    cmdline cmdl(options);
    cmdl.parse(argc, argv);
    tie(_input_file, _output_file) = opt_get_values();
    algochainStart(_input_file, _output_file);
}
