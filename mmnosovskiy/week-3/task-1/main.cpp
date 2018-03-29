#include <fstream>

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    std::string s;
    fin >> s;

    int len = s.length();
    int res = 0, zeros = 0;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == '0')
            ++zeros;
        else
            res += zeros;
    }

    fout << res;

    fin.close();
    fout.close();

    return 0;
}