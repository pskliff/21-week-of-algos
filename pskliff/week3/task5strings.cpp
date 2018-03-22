#include <iostream>
#include <algorithm>


using namespace std;


int main()
{
    string s1 = "29LsAAr37g4", s2 = "84fffa61AF3hL11", res = "";

    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    int i = 0, j = 0;
    while (i < s1.length() && j < s2.length())
    {
        if (s1[i] > s2[j]) ++j;
        else if (s1[i] == s2[j])
        {
            ++i;
        } else
        {
            res += s1[i];
            ++i;
        }
    }

    while(i < s1.length())
    {
        res += s1[i];
        ++i;
    }

    cout << (res == "" ? "-1" : res);
    return 0;
}

