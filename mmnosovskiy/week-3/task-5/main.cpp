#include <fstream>

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    std::string s1, s2, res;
    fin >> s1 >> s2;

    int size1 = s1.size(), size2 = s2.size();

    int i = 0, j = 0;

    while (i < size1 && j < size2)
    {
        while (i < size1 && s1[i] < s2[j])
            res += s1[i++];
        while (i < size1 && j < size2 && s1[i] == s2[j])
            ++i;
        while (j < size2 && s1[i] > s2[j])
            ++j;
    }

    if (!res.empty())
        fout << res;
    else
        fout << -1;

    fin.close();
    fout.close();

    return 0;
}