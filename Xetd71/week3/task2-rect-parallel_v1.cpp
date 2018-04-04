#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>

using namespace std;

/*
10
1 1
1 3
1 4
2 4
3 1
3 3
3 4
4 1
4 4
5 2
*/

/*
4
1 1
1 3
3 1
3 3
*/

struct PointEquals {
    bool operator()(const pair<int, int>& l, const pair<int, int>& r) const {
        return l.first < r.first && l.second < r.second;
    }
};

int main()
{
    int n;
    cin >> n;
    unordered_map<int, vector<int>> vertical;
    map<pair<int, int>, int, PointEquals> count;
    int sum = 0;
    for(int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        vertical[x].emplace_back(y);
        for(int j = 0; j < vertical[x].size() - 1; ++j) {
            pair<int, int> p = make_pair(vertical[x][j], y);
            if(count.count(p)) {
                sum += count[p];
                ++count[p];
            } else {
                count[p] = 1;
            }
        }
    }
    cout << sum;
    return 0;
}