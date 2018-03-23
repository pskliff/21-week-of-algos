#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);
    int N;
    fin >> N;
    double a[N], b[N];
    for (int i = 0; i < N; ++i)
    {
        fin >> a[i] >> b[i];
        a[i] /= 100;
        b[i] /= 100;
    }
    double full_prob = 0;
    for (int i = 0; i < N; ++i)
        full_prob += a[i] * b[i];

    for (int j = 0; j < N; ++j)
        fout << std::fixed << std::setprecision(12) << a[j] * b[j] / full_prob << std::endl;

    fin.close();
    fout.close();

    return 0;
}