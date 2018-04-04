//
// Created by Stas Don on 03/04/2018.
//

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<double , double> point;

//struct pair_hash {
//    size_t operator()(const point &p) const {
//        return hash<long long>()(((long long)p.first)^(((long long)p.second)<<32));
//    }
//};

bool isSymLine(const vector<point> points_vec)
{
    unordered_map<double, unordered_set<double>> points;
//    unordered_set<point, pair_hash> points;
    double x_sym_line = 0;
    int size = points_vec.size();

    for(auto p: points_vec) {
        if(points.find(p.first) == points.end())
        {
            points[p.first] = {p.second};
        }
        else
        {
            points[p.first].insert(p.second);
        }
//        points.insert({p.first, p.second});
        x_sym_line += p.first;
    }
    x_sym_line /= size;

    for(auto p: points_vec)
    {
        pair<double, double> sym_p;
        sym_p = {x_sym_line + (x_sym_line - p.first), p.second};
        if(points.find(sym_p.first) == points.end() || points[sym_p.first].find(sym_p.second) == points[sym_p.first].end())
            return false;
//        if(points.find(sym_p) == points.end())
//            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; ++i)
        cin >> points[i].first >> points[i].second;
    cout << isSymLine(points);
}
//
// 6
// 0 0 1 1 2 0 3 0 4 1 5 0
//
// 6
// 0 0 0 1 0 2 1 0 1 1 2 0
//
//5
//0 0 0 1 1 1 2 0 2 1