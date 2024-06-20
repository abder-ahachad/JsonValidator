#ifndef LEXER
#define LEXER

#include <cassert>
#include "utilities.h"
#define INVALID_TOKENIZATION Tokenization(list<Token>())
#define ERROR(list, i)  SHOW(list)\
        cout<<"error at char : "<<i<<endl;

enum Token {
    L_BRACE,    // {
    R_BRACE,    // }
    L_BRACKET,  // [
    R_BRACKET,  // ]
    COMMA,      // ,
    DOTS,       // :
    NULL_,
    BOOLEAN,
    NUMBER,
    STRING,
    END
};
string token_to_string(Token tk);

class Tokenization {
    const list<Token>& token_list;
    list<Token>::const_iterator current;
public :
    Tokenization(const list<Token>& token_list): token_list(token_list){
        current = this->token_list.begin();
    }
    Token next() {
        if(current == token_list.end())
            return END;
        Token token = *current;
        current++;
        return token;
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