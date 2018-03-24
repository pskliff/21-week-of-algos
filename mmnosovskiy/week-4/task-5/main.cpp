//
// Created by Lucky13 on 23.03.2018.
//

#include <iostream>
#include <fstream>
#include <cmath>

double f(double x, double c, double k, double m)
{
    return 49 / 2. * (x * x) + x * (7 * c - 5 * k) - m;
}

double findRoot(double c1, double k, double m)
{
    int n = 0;
    double a = -(7 * c1 - 5 * k) / 2 / 49 * 2., b = 1000000000, c, eps = 0.01;
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
        auto weeks = (unsigned long long) n;
        rest += (weeks * 5 * k) - (weeks * 7 * (2 * i + weeks * 7) / 2);
        i += weeks * 7;
        while (rest >= 0)
        {
            if (d != 6 && d != 7)
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