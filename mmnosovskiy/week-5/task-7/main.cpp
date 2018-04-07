#include <fstream>

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    int MAXD = 100;
    int a[MAXD] = {0};
    int N;
    fin >> N;
    for (int i = 0; i < N; ++i)
    {
        int ar, dep;
        fin >> ar >> dep;
        ++a[ar], --a[dep];
    }
    int max_p = -1, max_d = 0, cur_p = 0;

    for (int i = 0; i < MAXD; ++i)
    {
        cur_p += a[i];
        if (cur_p > max_p)
            max_p = cur_p, max_d = i;
    }

    fout << max_d;

    fin.close();
    fout.close();

    return 0;
}