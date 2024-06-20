#include "../inc/Parser.h"

bool parse_json(Tokenization& stream) {
    Token tk = stream.get_current();
    if(tk == L_BRACE) {
        stream.next();
        if(!parse_object(stream))
            return false;
        return stream.get_current() == END;
    }
    else if(tk == L_BRACKET) {
        stream.next();
        if(!parse_list(stream))
            return false;
        return stream.get_current() == END;
    }
    return false;
}

bool parse_object(Tokenization& stream) {
    Token tk = stream.get_current();
    if(tk == R_BRACE) {
        stream.next();
        return true;
    }
    if(!parse_pair(stream)) {
        return false;
    }
    tk = stream.get_current();
    while(tk == COMMA) {
        stream.next();
        if(!parse_pair(stream)) {
            return false;
        }
        tk = stream.get_current();
    }
    if(tk == R_BRACE) {
        stream.next();
        return true;
    }
    return false;
}

bool parse_list(Tokenization& stream) {
    Token tk = stream.get_current();
    if(tk == R_BRACKET) {
        stream.next();
        return true;
    }
    if(!parse_value(stream)) {
        return false;
    }
    tk = stream.get_current();
    while(tk == COMMA) {
        stream.next();
        if(!parse_value(stream)) {
            return false;
        }
        tk = stream.get_current();
    }
    if(tk == R_BRACKET) {
        stream.next();
        return true;
    }
    return false;
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
    Token tk = stream.get_current();
    if(tk == NUMBER || tk == STRING || tk == NULL_ || tk == BOOLEAN) {
        stream.next();
        return true;
    }
    if(tk == L_BRACE) {
        stream.next();
        return parse_object(stream);
    }
    if(tk == L_BRACKET) {
        stream.next();
        return parse_list(stream);
    }
    return false;
}