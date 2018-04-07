#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> tPoint;


bool check(int left, int right, int sym, vector<tPoint> points);

int main()
{
    ifstream fin;
    fin.open("in.txt");

    vector<tPoint> points;
    int sym;

    int n;
    double cnt = 0;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        int x,y;
        fin >> x >> y;
        points.emplace_back(x,y);
    }

    //O(nlog(n))
    sort(points.begin(), points.end());

    int left, right;
    if (n % 2 == 1)
    {
        sym = points[n / 2].first;
        right = n / 2 + 1;
    } else
    {
        sym = (points.front().first + points.back().first) / 2;
        right = n / 2;
    }
    left = n / 2 - 1;

    bool success = false;

    while(left >= 0)
    {
        if ((success = check(left, right, sym, points)))
            break;
        --left, ++right;
    }

    if (success)
        cout << sym << endl;
    else
        cout << "no symmetry" << endl;
    return 0;
}

bool check(int left, int right, int sym, vector<tPoint> points)
{
    return sym - points[left].first == points[right].first - sym &&
           points[left].second == points[right].second;
}