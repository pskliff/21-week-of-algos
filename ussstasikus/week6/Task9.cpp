//
// Created by Stas Don on 11/04/2018.
//
#include <iostream>

using namespace std;

bool isPalindrome(const string &s, size_t l, size_t r)
{
    while(l < r)
    {
        if(s[l] != s[r])
            return false;
        ++l;
        --r;
    }
    return true;
}

bool isAlmostPalindrome(const string &s)
{
    size_t l = 0, r = s.size() - 1;
    while(l < r)
    {
        if(s[l] != s[r])
        {
            return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
        }

        ++l;
        --r;
    }
    return true;

}

int main()
{

    string a;
    cin >> a;
    cout << isAlmostPalindrome(a);
}