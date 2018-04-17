#include <iostream>
#include <string>


using namespace std;


bool isPalindrome(string s)
{
    for (int i = 0, j = s.length() - 1; i < j; ++i, --j)
    {
        while(!isalnum(s[i]) && i < j) ++i;
        while(!isalnum(s[j]) && i < j) --j;
        if(tolower(s[i]) != tolower(s[j])) return false;
    }
    return true;
}

//bool isPalindrome(string s)
//{
//    size_t i = 0, j = s.length() - 1;
//    if (j == -1)
//        return true;
//    while (i < j)
//    {
//        char left = tolower(s[i]);
//        char right = tolower(s[j]);
//        if (!isalpha(left) && !isdigit(left))
//        {
//            ++i;
//            continue;
//        }
//        if(!isalpha(right) && !isdigit(right))
//        {
//            --j;
//            continue;
//        }
//
//        if (left != right)
//            return false;
//        ++i;
//        --j;
//    }
//    return true;
//}


int main()
{
    cout << isPalindrome("0P");
    return 0;
}