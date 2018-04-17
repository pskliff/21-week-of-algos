#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef pair<int,vector<int>> tPoint;


bool check(unordered_map<int, vector<int>> points, int av);

int main()
{
    ifstream fin;
    fin.open("in.txt");

    unordered_map<int, vector<int>> points;
    int sum = 0;

    int n;
    double cnt = 0;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        int x,y;
        fin >> x >> y;
        if (points.find(x) == points.end())
            points[x] = vector<int>();
        points[x].emplace_back(y);
        sum += x;
    }
    sum /= n;


    if (check(points, sum))
        cout << sum << endl;
    else
        cout << "no symmetry" << endl;
    return 0;
}

bool check(unordered_map<int, vector<int>> points, int av)
{
    for (auto &point : points)
    {
        int delta = 2 * (av - point.first);
        for (auto &it : point.second)
            if(find(points[point.first + delta].begin(), points[point.first + delta].end(), it)
               == points[point.first + delta].end())
                return false;
    }
    return true;
}