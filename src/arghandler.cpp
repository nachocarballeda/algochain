#include <fstream>
#include <string>
#include <sstream>
#include <tuple>

#include "../include/errorlog.h"
#include "../include/arghandler.h"

static string _input_file;
static string _output_file;

std::tuple<string, string> opt_get_values(void)
{
    return std::make_tuple(_input_file, _output_file);
}

void opt_set_output(string const &arg)
{
	std::stringstream out(arg);
	if (out.good())
		out >> _output_file;
}

void opt_set_input(string const &arg)
{
	if (arg == "-")
	{
		_input_file = "-";
	}
	else
	{
		std::stringstream in(arg);
		if (!in.good())
		{
			showError(MSG_ERROR_OPENING_A_FILE, "arghandler.cpp");
			exit(1);
		}
		in >> _input_file;
	}
}
