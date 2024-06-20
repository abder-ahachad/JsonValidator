#include "utilities.h"

bool is_hexadecimal(const string& s) {
    for(char c:s) {
        if(!isxdigit(c))
            return false;
    }
    return true;
}

string readFileToString(const string& filename) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Unable to open file: " + filename);
    }
    ostringstream content;
    content << file.rdbuf();
    return content.str();
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