//
// Created by Stas Don on 22/03/2018.
//

#include <iostream>
#include <map>

using namespace std;

int main()
{

    string a, b;
    cin >> a >> b;
    int n = 0;
    map<char, bool> checker;

    for(char symb: b)
        if(checker.find(symb) == checker.end())
            checker[symb] = true;
    for(char symb: a)
        if(checker.find(symb) == checker.end()) {
            cout << symb;
            ++n;
        }
    if(!n)
        cout << -1;
}