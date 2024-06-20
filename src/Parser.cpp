#include "../inc/Parser.h"

bool parse_json(Tokenization& stream) {
    if(stream.next() == L_BRACE) {
        if(!parse_object(stream))
            return false;
        return stream.next() == END;
    }
    return false;
}

bool parse_object(Tokenization& stream) {
    Token tk = stream.next();
    if(tk == R_BRACE) {
        return true;
    }
    if(!parse_pair(stream)) {
        return false;
    }
    tk = stream.next();
    while(tk == COMMA) {
        if(!parse_pair(stream)) {
            return false;
        }
        tk = stream.next();
    }
    return tk == R_BRACE;
}

bool parse_list(Tokenization& stream) {
    Token tk = stream.next();
    if(tk == R_BRACKET) {
        return true;
    }
    if(!parse_value(stream)) {
        return false;
    }
    tk = stream.next();
    while(tk == COMMA) {
        if(!parse_value(stream)) {
            return false;
        }
        tk = stream.next();
    }
    return tk == R_BRACKET;
}

bool parse_pair(Tokenization& stream) {
    if(!stream.match(STRING)) {
        return false;
    }
    if(!stream.match(DOTS)) {
        return false;
    }
    return parse_value(stream);
}

bool parse_value(Tokenization& stream) {
    Token tk = stream.next();
    if(tk == NUMBER || tk == STRING || tk == NULL_ || tk == BOOLEAN) {
        return true;
    }
    if(tk == L_BRACE) {
        return parse_object(stream);
    }
    if(tk == L_BRACKET) {
        return parse_list(stream);
    }
}