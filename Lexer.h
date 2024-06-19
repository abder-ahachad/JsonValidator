#include <string>
#include <list>
#include "utilities.h"

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
        return token_list.size();
    }
};

Tokenization tokenize(string& text) {
    list<Token> token_list;
    for(int i = 0; i < text.size(); ++i) {
        if(is_white_space(text[i])) {
            continue;
        }
        if(text[i] == '{') {
            token_list.push_back(Token(L_BRACE));
            continue;
        }
        if(text[i] == '}') {
            token_list.push_back(Token(R_BRACE));
            continue;
        }
        if(text[i] == '[') {
            token_list.push_back(Token(L_BRACKET));
            continue;
        }
        if(text[i] == ']') {
            token_list.push_back(Token(R_BRACKET));
            continue;
        }
        if(text[i] == ',') {
            token_list.push_back(Token(COMMA));
            continue;
        }
        if(text[i] == 'n') {
            if(text.substr(i, 4) == "null") {
                token_list.push_back(Token(NULL_));
                i+=3;
                continue;
            }
            else {
                return Tokenization(list<Token>()); 
            }
        }
        if(text[i] == 't') {
            if(text.substr(i, 4) == "true") {
                token_list.push_back(Token(BOOLEAN));
                i+=3;
                continue;
            }
            else {
                return Tokenization(list<Token>()); 
            }
        }
        if(text[i] == 'f') {
            if(text.substr(i, 4) == "false") {
                token_list.push_back(Token(BOOLEAN));
                i+=3;
                continue;
            }
            else {
                return Tokenization(list<Token>()); 
            }
        }
        if(is_numerical(text[i])){
            while(i<text.size() && is_numerical(text[i])) {
                i++;
            }
            token_list.push_back(Token(NUMBER));
            if(i == text.size())
                return Tokenization(token_list);
            i--;
        }

    }
}