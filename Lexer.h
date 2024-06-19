#ifndef LEXER
#define LEXER
#include <string>
#include <list>
#include "utilities.h"
#define INVALID_TOKENIZATION Tokenization(list<Token>())
using namespace std;

enum Token {
    L_BRACE,    // {
    R_BRACE,    // }
    L_BRACKET,  // [
    R_BRACKET,  // ]
    COMMA,      // ,
    NULL_,
    BOOLEAN,       
    NUMBER,        
    STRING
};

class Tokenization {
    const list<Token>& token_list;
    list<Token>::iterator current;
public :
    Tokenization(list<Token>& token_list): token_list(token_list){
        current = this->token_list.begin();
    }
    Token next() {
        current++;
        return *prev(current);
    }
    bool is_valid() {
        return token_list.size() != 0;
    }
};

#endif