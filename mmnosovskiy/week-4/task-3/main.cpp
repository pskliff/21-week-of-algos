//
// Created by Lucky13 on 23.03.2018.
//

#include <iostream>
#include <fstream>
#include <map>
#include <set>

int getMaxPrefix(const std::string &w1, const std::string &w2)
{
    int i = 0;
    int s1 = w1.size(), s2 = w2.size();
    while (i < s1 && i < s2 && w1[i] == w2[i])
        ++i;
    return i;
}

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    int N;
    fin >> N;

    std::set<std::string> dict;
    int res = 0;

    for (int i = 0; i < N; ++i)
    {
        std::string word;
        fin >> word;
        if (dict.find(word) != dict.end())
        {
            std::map<int, int> prefixes;
            for (auto &w : dict)
            {
                if (w == word)
                    continue;
                int len = getMaxPrefix(word, w);
                prefixes[len] += 1;
            }

            if (!prefixes.empty())
                res += prefixes.rbegin()->first + 1;
            else
                res += 1;

        }
        else
        {
            res += word.size();
            dict.insert(word);
        }
    }

    fout << res;

    fin.close();
    fout.close();

    return 0;
}