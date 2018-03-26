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

    int i = 0, j = 0;
    while(i < a.size() && j < b.size())
    {
        if(a[i] < b[j])
            cout<<a[i++];
        else if(a[i] > b[j])
            ++j;
        else
        {
            ++i;
            ++j;
        }
    }
}