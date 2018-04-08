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

    int i = 0, z_count = 0;
    while (i < N)
    {
        while (i < N && a[i] == 0)
            ++z_count, ++i;
        if (z_count > 0 && i < N)
            std::swap(a[i - z_count], a[i]);
        ++i;
    }

    for (int j = 0; j < N; ++j)
        fout << a[j] << " ";

    fin.close();
    fout.close();

    return 0;
}