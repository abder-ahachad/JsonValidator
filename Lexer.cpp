#include "Lexer.h"

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
                return INVALID_TOKENIZATION; 
            }
        }

        if(text[i] == 't') {
            if(text.substr(i, 4) == "true") {
                token_list.push_back(Token(BOOLEAN));
                i+=3;
                continue;
            }
            else {
                return INVALID_TOKENIZATION; 
            }
        }

        if(text[i] == 'f') {
            if(text.substr(i, 4) == "false") {
                token_list.push_back(Token(BOOLEAN));
                i+=3;
                continue;
            }
            else {
                return INVALID_TOKENIZATION; 
            }
        }

        if(is_numerical(text[i])){ // number token
            while(i<text.size() && is_numerical(text[i])) {
                i++;
            }
            if(i == text.size())
                return INVALID_TOKENIZATION;        // a json file can't end with a number
            token_list.push_back(Token(NUMBER));
            i--;
            continue;
        }

        if(text[i] == '"') {       // string token
            i++;
            while(i<text.size() && text[i]!='"') {
                if(text[i] == '\\'){
                    if(i == text.size()-1) {
                        return INVALID_TOKENIZATION;
                    }
                    if(text[i+1] == '/' || text[i+1] == '"' || text[i+1] == '\\' || text[i+1] == 'b' ||
                       text[i+1] == 'f' || text[i+1] == 'n' || text[i+1] == 'r' || text[i+1] == 't') {
                        i+=2;
                    }
                    else if(text[i+1] == 'u') {
                        if(i+5 >= text.size()) {
                            return INVALID_TOKENIZATION;
                        }
                        if(is_hexadecimal(text.substr(i+1, 4))) {
                            i+=5;
                        }
                        else {
                            return INVALID_TOKENIZATION;
                        }
                    }
                    else {
                        return INVALID_TOKENIZATION;
                    }
                }
                else {
                    i++;
                }
            }
            if(i == text.size()) {
                return INVALID_TOKENIZATION;        // a json file can't end with a string
            }
            token_list.push_back(Token(STRING));
            i--;
            continue;
        }

        return INVALID_TOKENIZATION;
    }
}