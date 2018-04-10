#include <fstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
    ifstream fin("input.txt", std::ios::in);
    ofstream fout("output.txt", std::ios::out);

    string t, p;
    fin >> t >> p;

    if (t.length() == 0)
    {
        fout << "TRUE";
        return 0;
    }
    if (p.length() == 0)
    {
        fout << "TRUE";
        return 0;
    }
    bool res = false;

    unordered_multiset<char> p_multiset;
    unordered_map<char, pair<int, int>> p_counts;

    for (char i : p)
        ++p_counts[i].first;

    for (int i = 0; i < t.length(); ++i)
    {
        if (p_counts.find(t[i]) == p_counts.end())
            p_multiset.clear();
        else
        {
            if (p_multiset.find(t[i]) == p_multiset.end())
            {
                p_counts[t[i]].second = i;
                p_multiset.insert(t[i]);
            }
            else if (p_multiset.count(t[i]) < p_counts[t[i]].first)
                p_multiset.insert(t[i]);
            else
            {
                p_multiset.clear();
                i = p_counts[t[i]].second;
            }
        }
        if (p_multiset.size() == p.length())
            res = true;
    }

    if (res)
        fout << "TRUE";
    else
        fout << "FALSE";

    fin.close();
    fout.close();

    return 0;
}