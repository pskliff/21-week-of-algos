#include <iostream>
#include <string>


using namespace std;

bool isNotBrokePalind(string& s, int l, int r, bool life)
{
    for (int i = l, j = r; i < j; ++i, --j)
        if (s[i] != s[j])
            if (life){
                life = false;
                bool first = isNotBrokePalind(s, i + 1, j, life);
                bool second = isNotBrokePalind(s, i, j - 1, life);
                return first || second;
            }
            else return false;
    return true;
}

bool isPalindrome(string s)
{
    bool life = true;

    return isNotBrokePalind(s, 0, s.length() - 1, life);
}

int main()
{
    cout << isPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");
//    cout << isPalindrome("abca");
    return 0;
}