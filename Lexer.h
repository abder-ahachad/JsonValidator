#include <string>
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


class Token {
    TokenType tocken_type;
    string lexeme;
};