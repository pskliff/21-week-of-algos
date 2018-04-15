#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    for(int i = 0, j = s.length() - 1; i < j; ++i, --j) {
        while(!isalnum(s[i])) ++i;
        while(!isalnum(s[j])) --j;
        if(i < j && toupper(s[i]) != toupper(s[j]))
            return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    cout << (isPalindrome(s) ? "true" : "false");
    return 0;
}