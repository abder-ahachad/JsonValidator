#include "utilities.h"

bool is_hexadecimal(const string& s) {
    for(char c:s) {
        if(!isxdigit(c))
            return false;
    }
    return true;
}
