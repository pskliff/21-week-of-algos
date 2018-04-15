#include <iostream>

using namespace std;

static int __ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

bool isPalindrome(const string& s, int i, int j) {
    while(i < j && s[i] == s[j]) { ++i; --j; }
    return i >= j;
}

bool validPalindrome(const string& s) {
    int i = 0, j = s.length() - 1;
    while(i < j && s[i] == s[j]) { ++i; --j; }
    return i >= j || isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
}

int main()
{
    string s;
    cin >> s;
    cout << validPalindrome(s);
    return 0;
}
