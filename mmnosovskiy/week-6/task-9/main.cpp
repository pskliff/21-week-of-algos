#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool validPalindrome(const string &s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            break;
        ++i;
        --j;
    }
    if (i >= j)
        return true;
    int i1 = i + 1, j1 = j;
    while (i1 < j1)
    {
        if (s[i1] != s[j1])
            break;
        ++i1;
        --j1;
    }
    if (i1 >= j1)
        return true;
    i1 = i, j1 = j - 1;
    while (i1 < j1)
    {
        if (s[i1] != s[j1])
            break;
        ++i1;
        --j1;
    }

    return i1 >= j1;
}

int main()
{
    ifstream fin("input.txt", std::ios::in);
    ofstream fout("output.txt", std::ios::out);

    string s;
    fin >> s;

    if (validPalindrome(s))
        fout << "TRUE";
    else fout << "FALSE";

    fin.close();
    fout.close();

    return 0;
}