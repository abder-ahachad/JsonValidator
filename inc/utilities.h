#ifndef UTILS
#define UTILS
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#define SHOW(list) cout<<"Tokénisation : ";\
    for(auto itr = list.begin(); itr!= list.end(); ++itr) {\
        cout<<token_to_string(*itr)<<" ";\
    }\
    cout<<endl;

using namespace std;


bool is_hexadecimal(const string& s);
string readFileToString(const string& filename);

#endif