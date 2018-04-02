#include <iostream>
#include <string>
using namespace std;

bool symbols[256];

int main()
{
    string s1, s2, res;
    cin >> s1 >> s2;
    for(char c : s2)
        symbols[c] = true;
    for(char c : s1)
        if(!symbols[c])
            res += c;
    cout << (res.empty() ? "-1" : res);
    return 0;
}