//
// Created by abder on 19/06/24.
//
#include "inc/Parser.h"
using namespace std;

int main() {
    string text = readFileToString("../test.json");
    cout<<"Chaine de caractère à évaluer : \n"<<text<<endl;

    Tokenization tokens_stream =  tokenize(text);
    if(!tokens_stream.is_valid())
        cout<<">> Format pas valide"<<endl;
    else {
        if(parse_json(tokens_stream))
            cout<<">> Format valide"<<endl;
        else
            cout<<">> Format pas valide"<<endl;
    }
}
