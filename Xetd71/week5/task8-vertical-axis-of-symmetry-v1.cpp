#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n % 2 != 0) {
        cout << "not found";
        return 0;
    }
    unordered_map<double, unordered_set<double>> points;
    double xAverage = 0, x, y;
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        xAverage += x;
        points[y].insert(x);
    }
    xAverage /= n;
    for(auto& pxs : points) {
        for(const double& px : pxs.second) {
            if(pxs.second.find(2 * xAverage - px) == pxs.second.end()) {
                cout << "not found";
                return 0;
            }
        }
    }
    cout << xAverage;
    return 0;
}

/*
6
2 2
3 1
3 2
5 1
5 2
6 2
*/
