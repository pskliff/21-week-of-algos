#include <iostream>
#include <vector>

typedef std::pair<double, double> point;
typedef std::pair<double, double> vector;
struct line {
    point p;
    vector v;

    line(point p1, point p2)
    {
        p.first = (p1.first + p2.first) / 2;
        p.second = (p1.second + p2.second) / 2;
        v.first = p1.first - p1.first;
        v.second = p1.second - p1.second;
    }
};

int main() {
    int n;
    std::cin >> n;
    point points[n];
    for(int i = 0; i < n; ++i)
        std::cin >> points[i].first >> points[i].second;


    std::vector<line> lines;
    for(int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            lines.emplace_back(line(points[i], points[j]));
        }
    }
    return 0;
}