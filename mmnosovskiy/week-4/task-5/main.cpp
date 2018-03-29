#include <fstream>
#include <cmath>

double f(double x, double c, double k, double m)
{
    return 49 / 2. * (x * x) + x * (7 * c - 5 * k - 3.5) - m;
}

double findRoot(double c1, double k, double m)
{
    int n = 0;
    double a = -(7 * c1 - 5 * k - 3.5) / 2 / 49 * 2., b = 1000000001, c, eps = 0.0001;
    do
    {
        c = (a + b) / 2;
        if (f(c, c1, k, m) * f(a, c1, k, m) <= 0) b = c;
        else a = c;

        n += 1;

    } while (fabs(a - b) >= eps);
    return c;
}

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    double k, m, rest;
    int d;

    fin >> k >> m >> d;

    rest = m;

    int i = 1;

    if (d != 1)
    {
        while (d % 7 != 1 && rest >= 0)
        {
            if (d != 6 && d != 7)
                rest += k;
            rest -= i++;
            ++d;
        }
    }
    d = 1;
    double n;
    if (rest < 0)
        fout << i - 2;
    else
    {
        n = findRoot(i, k, m);
        n = n < 1 ? n : n - 1;
        auto weeks = (unsigned long long) n;
        rest += (weeks * 5 * k) - (weeks * 7 * (i + weeks * 7 + i - 1) / 2);
        i += weeks * 7;
        while (rest >= 0)
        {
            if (d % 7 != 6 && d % 7 != 0)
                rest += k;
            rest -= i++;
            ++d;
        }
        fout << i - 2;
    }

    fin.close();
    fout.close();

    return 0;
}