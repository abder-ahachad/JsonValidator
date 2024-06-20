//
// Created by abder on 19/06/24.
//
#include "inc/Parser.h"
using namespace std;

int main() {
    string text = readFileToString("../test.json");
    cout<<"String to evaluate : \n"<<text<<endl;

    Tokenization tokens_stream =  tokenize(text);
    if(!tokens_stream.is_valid())
        cout<<"pas valide"<<endl;
    else {
        if(parse_json(tokens_stream))
            cout<<"valide"<<endl;
        else
            cout<<"pas valide"<<endl;
    }
}
