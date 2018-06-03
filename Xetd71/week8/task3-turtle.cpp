#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

pair<double, int> go(int wait, int v, int d, int n, vector<pair<int, int>>& dandelions) {
    double time = wait;
    int eaten = 0;
    for(int i = 0; i < n; ++i) {
        time += dandelions[i].first / v;
        if(time >= dandelions[i].second) {
            time += d;
            ++eaten;
        }
    }
    return {time, n - eaten};
};


int findPath(int v, int d, int n, vector<pair<int, int>>& dandelions, int s) {
    pair<double, int> time;
    int l = 0, r = dandelions.back().second;
    while(l < r) {
        int wait = (r + l) / 2;
        time = go(wait, v, d, n, dandelions);
    }
};

int main()
{
    int v, d, n;
    cin >> v >> d >> n;

    char c;
    int x, t1, t2, s = 0;
    vector<pair<int, int>> dandelions(n);
    cin >> x >> t1 >> c >> t2;
    dandelions.emplace_back({x, t1 * 60 + t2});
    for(int i = 1; i < n; ++i) {
        cin >> x >> t1 >> c >> t2;
        s += dandelions.back().first;
        dandelions.emplace_back({x - dandelions.back().first, t1 * 60 + t2});
    }
    s += dandelions.back().first;
    int res = findPath(v, d, n, dandelions, s);
    printf("%02d:%02d", res / 60, res % 60);
    return 0;
}