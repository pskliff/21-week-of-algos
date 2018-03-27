#include <fstream>
#include <utility>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <set>

typedef std::pair<int, int> point;

struct rect
{
    std::set<point> coord;

    rect(point p1, point p2, point p3, point p4)
    {
        coord.insert(p1);
        coord.insert(p2);
        coord.insert(p3);
        coord.insert(p4);
    }

    friend bool operator<(const rect &l, const rect &r)
    {
        return l.coord < r.coord;
    }
};

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    int N;
    fin >> N;

    point arr[N];

    std::unordered_map<int, std::unordered_map<int, int>> container_x;
    std::unordered_map<int, std::unordered_map<int, int>> container_y;

    for (int i = 0; i < N; ++i)
    {
        int x, y;
        fin >> x >> y;
        arr[i].first = x, arr[i].second = y;
        container_x[x][y] = y;
        container_y[y][x] = x;
    }

    std::set<rect> rects;
    for (auto &p : arr)
    {
        std::set<point> xs;
        std::set<point> ys;
        for (auto &item : container_x[p.first])
            xs.insert(point(p.first, item.second));
        for (auto &item : container_y[p.second])
            ys.insert(point(item.first, p.second));
        for (auto &x : xs)
            for (auto &y : ys)
            {
                if (x == y || x == p || y == p)
                    continue;
                if (container_x[x.second].count(y.first) != 0)
                    rects.insert(rect(p, x, y, point(y.first, x.second)));
            }
    }

    fout << rects.size();

    fin.close();
    fout.close();

    return 0;
}