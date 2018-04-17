#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int i = 0, j = s.length() - 1;
    bool used_one_life = false;
    string res = "polindrom";
    while (i < j)
    {
        if (s[i] != s[j])
        {
            if(used_one_life)
            {
                res = "nonpolindrom";
                break;
            }
            if(s[i] == s[j - 1])
                --j;
            else
                ++i;
            used_one_life = true;

        }else
            ++i, --j;

    }
    cout << res;

    return 0;
}

