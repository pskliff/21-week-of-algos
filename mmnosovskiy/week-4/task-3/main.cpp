#include <fstream>
#include <unordered_map>
#include <unordered_set>

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    int N;
    fin >> N;

    std::unordered_set<std::string> dict;
    std::unordered_map<std::string, int> prefixes;
    int res = 0;

    for (int i = 0; i < N; ++i)
    {
        std::string word;
        fin >> word;
        if (dict.find(word) != dict.end())
        {
            std::string prefix;
            int len = word.size();
            int j;
            for (j = 0; j < len - 1; ++j)
            {
                prefix += word[j];
                if (prefixes.find(prefix) != prefixes.end())
                    if (prefixes[prefix] == 1 && dict.find(prefix) == dict.end())
                        break;
            }
            res += j + 1;
        }
        else
        {
            std::string prefix;
            int len = word.size();
            for (int j = 0; j < len - 1; ++j)
            {
                prefix += word[j];
                prefixes[prefix] += 1;
            }
            dict.insert(word);
            res += word.size();
        }
    }

    fout << res;

    fin.close();
    fout.close();

    return 0;
}