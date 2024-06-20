#include "../inc/utilities.h"

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
