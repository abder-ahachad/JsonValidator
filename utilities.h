#ifndef UTILS
#define UTILS
#include <string>
using namespace std;
#define FILENAME "test.json"

bool is_hexadecimal(const string& s) {
    for(char c:s) {
        if(!isxdigit(c))
            return false;
    }
    return true;
}


#endif