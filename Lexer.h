#ifndef LEXER
#define LEXER

#include "utilities.h"
#define INVALID_TOKENIZATION Tokenization(list<Token>())

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
        current++;
        return *prev(current);
    }
    bool is_valid() {
        return token_list.size() != 0;
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