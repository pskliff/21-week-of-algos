#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n % 2 != 0) {
        cout << "not found";
        return 0;
    }
    double xAverage = 0, x, y;
    vector<pair<double, double>> points;
    points.reserve(n);
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        xAverage += x;
        points.emplace_back(x, y);
    }
    xAverage /= n;

    sort(
            points.begin(),
            points.end(),
            [](const pair<double, double>& r, const pair<double, double>& l) {
                return r.second < l.second || (r.second == l.second && r.first < l.first);
            }
    );

    int i = 0, s = 0;
    for(; i < n - 1; ++i) {
        if(points[i].second == points[i + 1].second)
            ++s;
        else {
            for(int j = 0; j <= s / 2; ++j) {
                pair<double, double> p1 = points[i - s + j], p2 = points[i - j];
                if(p1.second != p2.second || xAverage * 2 - p1.first != p2.first) {
                    cout << "not found";
                    return 0;
                }
            }
            s = 0;
        }
    }
    for(int j = 0; j <= s; ++j) {
        pair<double, double> p1 = points[i - s + j], p2 = points[i - j];
        if(p1.second != p2.second || xAverage * 2 - p1.first != p2.first) {
            cout << "not found";
            return 0;
        }
    }

    cout << xAverage;
    return 0;
}