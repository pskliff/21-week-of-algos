//
// Created by Lucky13 on 23.03.2018.
//

#include <iostream>
#include <fstream>
#include <cmath>

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
        double t = (7 * i - 5 * k) / 2.;
        double t2 = t * t;
        double D = t2 + 49 * rest;
        n = (-(7 * i - 5 * k) / 2. + std::sqrt(D)) / 49 / 2;
        auto weeks = (unsigned long long) n;
        rest += weeks * 5 * k;
        rest -= weeks * 7 * (2 * i + weeks * 7) / 2;
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