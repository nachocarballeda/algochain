#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

//#include "include/body.h"
#include "include/header.h"
//#include "include/block.h"
//#include "include/sha256.h"
//#include "include/cmdline.h"

#define MSG_ERR_OPEN_FILE "Error al abrir el archivo "

using namespace std;

/*static void opt_input(string const &arg);
 
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
}*/

int main(int argc, char *argv[])
{
    /*Block block0;
	cmdline cmdl(options);
	
	cmdl.parse(argc, argv);

    string output = sha256(input);
    cout << "input: " << input << endl;
    cout << "output: " << output << endl;*/
	
	size_t b = 5;
	Header h(b);

	cout << h << endl;

	Header h1;
	cout << h1 << endl;

	Header h2(h);
	cout  << h2 << endl;

	h2.setBits(10);
	cout  << h2 << endl;

	cout << h2.getBits() << endl; 
	cout << h2.getNonce() << endl; 
	cout << h2.getPrevBlock() << endl; 

	Header h3 = h2;

	cout << h3 << endl;

	h3.setTxnsHash("Hola");
	cout << h3.getTxnsHash() << endl;

}
