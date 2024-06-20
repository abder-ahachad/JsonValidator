#ifndef PARSER
#define PARSER

#include "Lexer.h"
bool parse_json(Tokenization& stream);
bool parse_object(Tokenization& stream);
bool parse_list(Tokenization& stream);
bool parse_pair(Tokenization& stream);
bool parse_value(Tokenization& stream);

#endif