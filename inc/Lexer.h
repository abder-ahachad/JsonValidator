#ifndef LEXER
#define LEXER

#include <cassert>
#include "utilities.h"
#define INVALID_TOKENIZATION Tokenization(list<Token>())
#define ERROR(list, i)  SHOW(list)\
        cout<<"error at char : "<<i<<endl;

enum Token {
    L_BRACE = 0,    // {
    R_BRACE = 1,    // }
    L_BRACKET = 2,  // [
    R_BRACKET = 3,  // ]
    COMMA = 4,      // ,
    DOTS = 5,       // :
    NULL_ = 6,
    BOOLEAN = 7,
    NUMBER = 8,
    STRING = 9,
    END = 10
};
string token_to_string(Token tk);

class Tokenization {
    const list<Token> token_list;
    list<Token>::const_iterator current;
public :
    Tokenization(list<Token> token_list): token_list(token_list){
        current = this->token_list.begin();
    }
    Token get_current() {
        if(current == token_list.end())
            return END;
        return *current;
    }
    void next() {
        if(current == token_list.end())
            return;
        current++;
    }
    bool is_valid() {
        return !token_list.empty();
    }
    bool match(Token tk) {
        if(current == token_list.end())
            return tk == END;
        current++;
        return tk == *prev(current);
    }
};

Tokenization tokenize(string& text);
#endif