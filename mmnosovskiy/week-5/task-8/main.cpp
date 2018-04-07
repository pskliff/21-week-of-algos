#include <fstream>
#include <unordered_map>

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    int N;
    fin >> N;
    std::unordered_map<double, std::unordered_map<double, double>> dots;
    std::pair<double, double> d[N];
    double sum_x = 0;
    for (int i = 0; i < N; ++i)
    {
        double x, y;
        fin >> x >> y;
        dots[x][y] = y;
        d[i].first = x;
        d[i].second = y;
    }

    double sym_x = sum_x / N;
    bool error = false;

    for (int i = 0; i < N; ++i)
    {
        double x = d[i].first, y = d[i].second;
        if (!(dots.find(-x) != dots.end()
              && dots[-x].find(y) != dots[-x].end()))
        {
            error = true;
            break;
        }
    }
    if (error)
        fout << "NO";
    else
        fout << "YES";

    fin.close();
    fout.close();

    return 0;
}