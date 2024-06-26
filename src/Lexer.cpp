#include "../inc/Lexer.h"

Tokenization tokenize(string& text) {
    list<Token> token_list;
    for(int i = 0; i < text.size(); ++i) {
        if(isspace(text[i])) {
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
        if(text[i] == ':') {
            token_list.push_back(Token(DOTS));
            continue;
        }

        if(text[i] == 'n') {
            if(i+3 >= text.size()) {
                ERROR(token_list,i)
                return INVALID_TOKENIZATION;
            }
            if(text.substr(i, 4) == "null") {
                token_list.push_back(Token(NULL_));
                i+=3;
                continue;
            }
            else {
                ERROR(token_list, i)
                return INVALID_TOKENIZATION; 
            }
        }

        if(text[i] == 't') {
            if(i+3 >= text.size()) {
                ERROR(token_list,i)
                return INVALID_TOKENIZATION;
            }
            if(text.substr(i, 4) == "true") {
                token_list.push_back(Token(BOOLEAN));
                i+=3;
                continue;
            }
            else {
                ERROR(token_list,i)
                return INVALID_TOKENIZATION; 
            }
        }

        if(text[i] == 'f') {
            if(i+4 >= text.size()) {
                ERROR(token_list,i)
                return INVALID_TOKENIZATION;
            }
            if(text.substr(i, 5) == "false") {
                token_list.push_back(Token(BOOLEAN));
                i+=4;
                continue;
            }
            else {
                ERROR(token_list,i)
                return INVALID_TOKENIZATION; 
            }
        }

        if(isdigit(text[i])){ // number token
            while(i<text.size() && isdigit(text[i])) {
                i++;
            }
            if(i == text.size()) {
                ERROR(token_list,i)
                return INVALID_TOKENIZATION;        // a json file can't end with a number
            }
            token_list.push_back(Token(NUMBER));
            i--;
            continue;
        }

        if(text[i] == '"') {       // string token
            i++;
            while(i<text.size() && text[i]!='"') {
                if(text[i] == '\\'){
                    if(i == text.size()-1) {
                        ERROR(token_list,i)
                        return INVALID_TOKENIZATION;
                    }
                    if(text[i+1] == '/' || text[i+1] == '"' || text[i+1] == '\\' || text[i+1] == 'b' ||
                       text[i+1] == 'f' || text[i+1] == 'n' || text[i+1] == 'r' || text[i+1] == 't') {
                        i+=2;
                    }
                    else if(text[i+1] == 'u') {
                        if(i+5 >= text.size()) {
                            ERROR(token_list,i)
                            return INVALID_TOKENIZATION;
                        }
                        if(is_hexadecimal(text.substr(i+1, 4))) {
                            i+=5;
                        }
                        else {
                            ERROR(token_list,i)
                            return INVALID_TOKENIZATION;
                        }
                    }
                    else {
                        ERROR(token_list,i)
                        return INVALID_TOKENIZATION;
                    }
                }
                else {
                    i++;
                }
            }
            if(i == text.size() || i == text.size() - 1) {
                ERROR(token_list,i)
                return INVALID_TOKENIZATION;        // a json file can't end with a string
            }
            token_list.push_back(Token(STRING));
            continue;
        }
        ERROR(token_list,i)
        return INVALID_TOKENIZATION;
    }
    return Tokenization(token_list);
}

string token_to_string(Token tk) {
    switch(tk) {
        case Token::BOOLEAN:
            return "BOOLEAN";
        case Token::COMMA:
            return "COMMA";
        case Token::DOTS:
            return "DOTS";
        case Token::END:
            return "END";
        case Token::L_BRACE:
            return "L_BRACE";
        case Token::R_BRACE:
            return "R_BRACE";
        case Token::L_BRACKET:
            return "L_BRACKET";
        case Token::R_BRACKET:
            return "R_BRACKET";
        case Token::NULL_:
            return "NULL";
        case Token::NUMBER:
            return "NUMBER";
        default:
            return "STRING";
    }
}