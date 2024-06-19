#include <string>
#include <list>
#include "utilities.h"
using namespace std;

enum TokenType {
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

struct Token {
    TokenType token_type;
    string lexeme;
    Token(TokenType token_type, const string& lexeme): 
            token_type(token_type), lexeme(lexeme) {}
};

class Tokenization {
    list<Token>& token_list;
    list<Token>::iterator current;
public :
    Tokenization(list<Token>& token_list): token_list(token_list){
        current = this->token_list.begin();
    }
    Token next() {
        current++;
        return *prev(current);
    }
};

Tokenization tokenize(string& text) {
    list<Token> token_list;
    for(int i = 0; i<text.size(); ++i) {
        if(is_white_space(text[i])) {
            continue;
        }
        if(text[i] == '{') {
            token_list.push_back(Token(L_BRACE, '{'));
            continue;
        }
        if(text[i] == '}') {
            token_list.push_back(Token(R_BRACE, '}'));
            continue;
        }
        if(text[i] == '[') {
            token_list.push_back(Token(L_BRACKET, '['));
            continue;
        }
        if(text[i] == ']') {
            token_list.push_back(Token(R_BRACKET, ']'));
            continue;
        }
        ...
    }
}