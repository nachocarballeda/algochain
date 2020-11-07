#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

//#include "include/body.h"
#include "include/header.h"
#include "include/block.h"
#include "include/sha256.h"
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

	cout << "PRUEBAS HEADER" << endl;


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
	h3.incrementNonce();
	cout << h3 << endl;

	h3.setTxnsHash("Hola");
	cout << h3.getTxnsHash() << endl;

	cout << "PRUEBAS BLOQUE" << endl;

	Block b1;

	b1.setHeader(h1);

	cout << b1 << endl;

	Header h4 = b1.getHeader();

	cout << h4 << endl;


	b1.updateTxnsHash();


	//Falta la funcion de concatencion de transacciones el updateTxnsHash.
	//Falta el proof of work verificando la dificultad. Ambas deberian estar en privadas del bloque.

	string s = h4.cat();

	cout << s;

	Header h5;
	h5.setBits(3);
	h5.setTxnsHash("155dc94b29dce95bb2f940cdd2d7e0bce66dca9370c3ed96d50a30b3d84f8c4c");

	Block b2;

	b2.setHeader(h5);
	b2.proofOfWork(); //Tiene comentarios de prueba.
	//El proofofwork se debe llamar desde la funcion updateTxnsHash, pero como
	//faltan las funciones del body se pone aqui como prueba.

}
