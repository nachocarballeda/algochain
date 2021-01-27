#ifndef _ARGHANDLER_H_
#define _ARGHANDLER_H_

#include "cmdline.h"
#include <string>

std::tuple<string, string> opt_get_values(void);
void opt_set_output(string const &arg);
void opt_set_input(string const &arg);
void opt_get_values(string &in, string &out);

#endif