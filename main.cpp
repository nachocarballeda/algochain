#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "include/sha256.h"
#include "include/cmdline.h"

#define MSG_ERR_OPEN_FILE "Error al abrir el archivo "

using namespace std;

static void opt_input(string const &arg);
 
static option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{0, }
};

static string input;

static void opt_input(string const &arg)
{
	if(arg == "-") {
		cin >> input;
	}
	else{
		std::stringstream in(arg);
	    if(!in.good()){
		    cerr << MSG_ERR_OPEN_FILE << arg << endl;
		    exit(1);
	    }
		in >> input;
	}
}

int main(int argc, char *argv[])
{
	cmdline cmdl(options);
	
	cmdl.parse(argc, argv);

    string output = sha256(input);
    cout << "input: " << input << endl;
    cout << "output: " << output << endl;

    return 0;
}
