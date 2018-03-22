//
// Created by Lucky13 on 20.03.2018.
//

#include <vector>
#include <iostream>
#include <fstream>

typedef std::pair<double, double> dot;
typedef std::pair<std::pair<double, double>, dot> line;

bool check_lines(std::pair<double, double> &x, std::pair<double, double> &y);

int main()
{
    int N;
    bool res;
    std::ifstream fin("input.txt", std::ios::in);
    fin >> N;
    std::vector<std::pair<double, double>> dots;
    for (int i = 0; i < N; ++i)
    {
        double x, y;
        fin >> x >> y;
        dots.emplace_back(std::make_pair(x, y));
    }

    std::pair<double, double> currentDot = dots[0];
    for (int i = 1; i < N; ++i)
    {
        if (check_lines(currentDot, dots[i]))
        {
            res = true;
            break;
        }
    }
}

bool check_lines(std::pair<double, double> &x, std::pair<double, double> &y, std::vector<double, double>& dots)
{
    line symmetry(std::make_pair(y.first - x.first, y.second - x.second), x);


}