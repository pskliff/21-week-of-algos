#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n0 = 0, sum = 0;
    for(char& c : s) {
        if(c == '0')
            ++n0;
        else
            sum += n0;
    }
    cout << sum;
    return 0;
}