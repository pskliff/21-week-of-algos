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
    int cnt = 0;
    vector<tPoint> points;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        int x,y;
        fin >> x >> y;
        points.emplace_back(x,y);
    }

    //point a - on the diagonal
    for (auto it1 = points.begin(); it1 != points.end(); ++it1)
    {
        //point c - on the diagonal
        for (auto it2 = it1 + 1; it2 != points.end(); ++it2)
        {
            //point d - looking for couple b
            for (auto it3 = it2 + 1; it3 != points.end(); ++it3)
            {
                auto b_target = find(points.begin(), points.end(),
                                     make_pair(it1->first + it2->first - it3->first,
                                               it1->second + it2->second - it3->second));

                if (b_target != points.end() &&
                    b_target != it1 && b_target !=it2 && b_target != it3)
                    cnt++;
            }

        }
    }

    cout << cnt / 3 << endl;

    return 0;
}

