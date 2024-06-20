//
// Created by abder on 19/06/24.
//
#include "inc/Parser.h"
using namespace std;

int main() {
    string text = readFileToString("../test.json");
    cout<<text<<endl;
    Tokenization tokens_stream =  tokenize(text);
    if(!tokens_stream.is_valid())
        cout<<"pas valide"<<endl;
    else {
        if(parse_json(tokens_stream))
            cout<<"valid"<<endl;
        else
            cout<<"pas valide"<<endl;
    }
}
