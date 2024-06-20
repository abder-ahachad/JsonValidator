#ifndef UTILS
#define UTILS
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Lexer.h"

using namespace std;
#define FILENAME "test.json"

bool is_hexadecimal(const string& s);
string readFileToString(const string& filename);
string token_to_string(Token tk);

#endif