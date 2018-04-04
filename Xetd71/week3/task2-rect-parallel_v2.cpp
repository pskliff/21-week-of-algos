#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n, sum = 0;
    cin >> n;
    vector<pair<int, int>> points;
    unordered_map<int, unordered_set<int>> vertical;
    for(int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        points.emplace_back(make_pair(x, y));
        vertical[x].insert(y);
    }

    for(int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(points[i].first != points[j].first && points[i].second != points[j].second &&
               vertical[points[i].first].find(points[j].second) != vertical[points[i].first].end() &&
               vertical[points[j].first].find(points[i].second) != vertical[points[j].first].end())
                ++sum;
        }
    }
    cout << sum / 2;
    return 0;
}