#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

#include "include/body.h"
#include "include/header.h"
#include "include/block.h"
#include "include/sha256.h"
#include "include/cmdline.h"

#define MSG_ERR_OPEN_FILE "Error al abrir el archivo "

using namespace std;

static void _opt_set_input(string const &arg);
static void _opt_set_output(string const &arg);
static void _opt_set_difficulty(string const &arg);

static option_t options[] = {
    {1, "d", "difficulty", "-", _opt_set_difficulty, OPT_MANDATORY},
    {1, "o", "output", "-", _opt_set_output, OPT_DEFAULT},
	{1, "i", "input", "-", _opt_set_input, OPT_DEFAULT},
	{0, }
};

static string g_input;
static string g_output;
static size_t g_difficulty;

static void _opt_set_difficulty(string const &arg)
{
    char * pEnd;
    g_difficulty = strtol(arg.c_str(), &pEnd, 10);
    cout << "Difficulty is " << g_difficulty << endl;
}

static void _opt_set_output(string const &arg)
{
    std::stringstream out(arg);
    out >> g_output;
}

static void _opt_set_input(string const &arg)
{
	if(arg == "-") {
		cin >> g_input;
	}
	else{
		std::stringstream in(arg);
	    if(!in.good()){
		    cerr << MSG_ERR_OPEN_FILE << arg << endl;
		    exit(1);
	    }
		in >> g_input;
	}
}

int main(int argc, char *argv[])
{
	cmdline cmdl(options);
	cmdl.parse(argc, argv);

	Block block0(g_input);
	block0.writeToFile(g_output);
}
