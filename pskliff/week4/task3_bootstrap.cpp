#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main()
{
    int n = 0, res = 0;
    cin >> n;
    string word = "";
    unordered_set<string> dict;
    unordered_map<string, int> prefixes;
    for (int i = 0; i < n; ++i)
    {
        cin >> word;
        string prefix = "";
        if (dict.find(word) == dict.end())
        {
            dict.insert(word);

            for (int j = 0; j < word.length() - 1; ++j)
            {
                prefix += word[j];
                prefixes[prefix] += 1;
            }
            res += word.length();
        }
        else
        {
            int m_pref = word.length();
            for (int j = 0; j < word.length() - 1; ++j)
            {
                prefix += word[j];

                if (prefixes[prefix] == 1 && dict.find(prefix) == dict.end())
                {
                    m_pref = prefix.length();
                    break;
                }
            }

            res += m_pref;
        }


    }

    cout << res;
    return 0;
}

