#include <fstream>
#include <utility>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <set>

typedef std::pair<double, double> point;

double len2(point p1, point p2)
{
    return (p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second);
}

const point center(const point &p1, const point &p2)
{
    return {(p1.first + p2.first) / 2, (p1.second + p2.second) / 2};
}

const point operator*(const double &l, const point &r)
{
    return {r.first * l, r.second * l};
}

const point operator+(const point &l, const point &r)
{
    return {l.first + r.first, l.second + r.second};
}

const point operator-(const point &l, const point &r)
{
    return {l.first - r.first, l.second - r.second};
}

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    int N;
    fin >> N;

    point arr[N];

    std::unordered_map<int, std::unordered_map<int, int>> container;

    for (int i = 0; i < N; ++i)
    {
        int x, y;
        fin >> x >> y;
        arr[i].first = x, arr[i].second = y;
        container[x][y] = y;
    }

    int count = 0;
    for (int i = 0; i < N - 2; ++i)
        for (int j = i + 1; j < N - 1; ++j)
            for (int k = j + 1; k < N; ++k)
            {
                point dl = arr[i];
                point ur = arr[j];
                point dr = arr[k];

                double a2 = len2(dr, ur), b2 = len2(dl, dr), c2 = len2(dl, ur);
                if (a2 > c2)
                {
                    std::swap(a2, c2);
                    std::swap(dr, dl);
                }
                if (b2 > c2)
                {
                    std::swap(b2, c2);
                    std::swap(dr, ur);
                }
                if (c2 != a2 + b2)
                    continue;

                point ul = dr + 2 * (center(dl, ur) - dr);
                if (container.find(ul.first) != container.end()
                    && container[ul.first].find(ul.second) != container[ul.first].end())
                    ++count;
            }

    fout << count / 4;

    fin.close();
    fout.close();

    return 0;
}