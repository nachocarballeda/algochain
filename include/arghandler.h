#ifndef _ARGHANDLER_H_
#define _ARGHANDLER_H_

#include "cmdline.h"
#include <string>

void opt_set_difficulty(string const &arg);
void opt_set_output(string const &arg);
void opt_set_input(string const &arg);
std::tuple<string, string, size_t> opt_get_values(void);

#endif