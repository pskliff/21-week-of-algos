#include <iostream>

using namespace std;



bool validPalindrome(string& s) {
    int i = 0, j = s.length() - 1;
    while(i < j && s[i] == s[j]) {
        ++i;
        --j;
    }
    if(i >= j)
        return true;

    int i1 = i + 1, j1 = j;
    while(i1 < j1 && s[i1] == s[j1]) {
        ++i1;
        --j1;
    }
    if(i1 >= j1)
        return true;

    --j;
    while(i < j) {
        if(s[i] != s[j])
            return false;
        ++i;
        --j;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    cout << validPalindrome(s);
    return 0;
}
