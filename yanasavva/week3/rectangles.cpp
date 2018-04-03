#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> tPoint;

int main()
{
    ifstream fin;
    fin.open("input.txt");
    int n;
    double cnt = 0;
    vector<tPoint> points;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        int x,y;
        fin >> x >> y;
        points.emplace_back(x,y);
    }

    for (auto it1 = points.begin(); it1 != points.end(); ++it1)
    {
        for (auto it2 = it1 + 1; it2 != points.end(); ++it2)
        {
            auto b_target = find(points.begin(), points.end(), make_pair(it2->first, it1->second));
            auto d_target = find(points.begin(), points.end(), make_pair(it1->first, it2->second));
            if (b_target != points.end() &&
                d_target != points.end() &&
                    b_target != it1 && b_target !=it2 &&
                    d_target != it1 && d_target != it2)
                cnt++;

        }
    }

    cout << cnt / 2 << endl;

    return 0;
}

