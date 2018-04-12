#include<fstream>
#include<vector>
#include <unordered_map>

using namespace std;

bool isPalindrome(string s)
{
    if (s.empty())
        return true;
    size_t i = 0, j = s.length() - 1;
    while (i < j)
    {
        while (i < s.length() && !(isalpha(s[i]) || isdigit(s[i])))
            ++i;
        while (j > 0 && !(isalpha(s[j]) || isdigit(s[j])))
            --j;
        if (i >= j)
            return true;
        unsigned char c1 = (unsigned char) s[i], c2 = (unsigned char) s[j];
        if (isalpha(c1))
            c1 = tolower(c1);
        if (isalpha(c2))
            c2 = tolower(c2);
        if (c1 != c2)
            return false;
        ++i;
        --j;
    }
    return true;
}

int main()
{
    ifstream fin("input.txt", std::ios::in);
    ofstream fout("output.txt", std::ios::out);

    string s;
    fin >> skipws >> s;

    fout << isPalindrome(s);

    fin.close();
    fout.close();

    return 0;
}