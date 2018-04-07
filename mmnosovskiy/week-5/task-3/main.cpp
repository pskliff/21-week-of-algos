#include <fstream>

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    int N;

    fin >> N;
    int a[N];
    for (int i = 0; i < N; ++i)
        fin >> a[i];

    int i = a[0] == 0 ? 1 : 0, max_len = 0, left = 0, right = 0;
    while (i < N)
    {
        while (a[i] == 1)
            ++right, ++i;
        if (i < N)
        {
            if (left + right > max_len)
                max_len = left + right;
            left = right;
            right = 0;
            if (a[i - 1] == 0)
                left = 0;
        }
        ++i;
    }

    if (max_len == 0 && right > 0)
        max_len = right == N ? right - 1 : right;

    fout << max_len;

    fin.close();
    fout.close();

    return 0;
}