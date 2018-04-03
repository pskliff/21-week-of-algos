#include<iostream>
#include <limits>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const double INF = std::numeric_limits<double>::infinity();
const pair<double, double> INF_POINT = make_pair(INF, INF);

pair<double, double> subtract(pair<double, double> p1, pair<double, double> p2) {
    return make_pair(p1.first - p2.first, p1.second - p2.second);
};

pair<double, double> add(pair<double, double> p1, pair<double, double> p2) {
    return make_pair(p1.first + p2.first, p1.second + p2.second);
};

double scalarProduct(pair<double, double> p1, pair<double, double> p2) {
    return p1.first * p2.first + p1.second * p2.second;
};

pair<double, double> getRectPoint(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3) {
    if((p2.first - p1.first) / (p2.second - p1.second) == (p3.first - p1.first) / (p3.second - p1.second))
        return INF_POINT;

    pair<double, double> v21 = subtract(p2, p1), v31 = subtract(p3, p1), v32 = subtract(p3, p2);
    if(scalarProduct(v21, v31) == 0)
        return add(p1, add(v21, v31));
    if(scalarProduct(v21, v32) == 0)
        return add(p2, subtract(v32, v21));
    if(scalarProduct(v31, v32) == 0)
        return add(p3, subtract(subtract(p1, p3), v32));
};

struct PointEquals {
    bool operator()(const pair<double, double>& l, const pair<double, double>& r) const {
        return l.first == r.first && l.second == r.second;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<pair<double, double>> points;
    unordered_map<double, unordered_set<double>> pointStorage;
    for(int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        pair<double, double> p = make_pair(x, y);
        points.emplace_back(p);
        pointStorage[p.first].insert(p.second);
    }

    int sum = 0;
    for(int i = 0; i < n - 2; ++i) {
        for(int j = i + 1; j < n - 1; ++j) {
            for(int k = j + 1; k < n; ++k) {
                pair<double, double> p = getRectPoint(points[i], points[j], points[k]);
                if(pointStorage[p.first].find(p.second) != pointStorage[p.first].end())
                    ++sum;
            }
        }
    }
    cout << sum / 4;

    return 0;
}