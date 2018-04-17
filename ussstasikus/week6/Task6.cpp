//
// Created by Stas Don on 11/04/2018.
//

#include <iostream>
#include <unordered_map>
using namespace std;

bool isSubstr(const string &a, const string &b)
{
    unordered_map<char, int> symbs;

    for(auto c: b)
    {
        if(symbs.find(c) == symbs.end())
            symbs[c] = 1;
        else
            symbs[c] += 1;
    }

    size_t matched = 0;
    size_t sub_size = b.size();

    for (int i = 0; i < sub_size; ++i)
    {
        if(symbs.find(a[i]) != symbs.end())
        {
            if (symbs[a[i]] > 0)
                ++matched;
            symbs[a[i]] -= 1;
        }
        if(matched == sub_size)
            return true;
    }

    for (size_t start = 1; start < a.size() - sub_size + 1; ++start)
    {
        if(symbs.find(a[start - 1]) != symbs.end())//восстановление
        {
            if(symbs[a[start - 1]] >= 0)
                --matched;
            symbs[a[start - 1]] += 1;
        }

        if(symbs.find(a[start + sub_size - 1]) != symbs.end() )//&& symbs[a[start + sub_size - 1]] != 0)
        {
            if (symbs[a[start + sub_size - 1]] > 0)
                ++matched;
            symbs[a[start + sub_size - 1]] -= 1;
        }

        if(matched == sub_size)
            return true;
    }
    return false;
}


int main()
{
    string a, b;
    cin >> a >> b;
    cout << isSubstr(a, b);
}

//abbdca
//bbd


