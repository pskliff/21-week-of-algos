#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main()
{
    const int n = 8;
//    pair<int, int> points[n] = {make_pair(1,1), make_pair(1,3), make_pair(1,4), make_pair(2,4), make_pair(3,1),
//                                make_pair(3,3), make_pair(3,4), make_pair(4,1), make_pair(4,4), make_pair(5,2)}; // 5

    pair<int, int> points[n] = {make_pair(-2,4), make_pair(4,10), make_pair(7,7), make_pair(1,1),
                                make_pair(3,3), make_pair(5,1), make_pair(5,5), make_pair(7,3),
                                make_pair(-2,0), make_pair(-5,0), make_pair(-5,4), make_pair(-2,6), make_pair(-5,6),
                                make_pair(-8,0), make_pair(-8,6)}; // 7

//    pair<int, int> points[n] = {make_pair(-2,4), make_pair(4,10), make_pair(7,7), make_pair(1,1),
//                                make_pair(3,3), make_pair(5,1), make_pair(5,5), make_pair(7,3)}; // 2

    int count = 0;
    unordered_map<int, unordered_set<int>> hash_points;
    for (auto el : points)
        hash_points[el.first].insert(el.second);

    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                int x1 = points[i].first, y1 = points[i].second;
                int dx1 = x1 - points[j].first, dy1 = y1 - points[j].second;
                int dx2 = points[k].first - points[j].first, dy2 = points[k].second - points[j].second;
                if (dx1 * dx2 + dy1 * dy2 != 0)
                    continue;
                int x_new = x1 + dx2, y_new = y1 + dy2;
                if (hash_points.find(x_new) != hash_points.end() && hash_points[x_new].find(y_new) != hash_points[x_new].end())
                    ++count;
            }
        }
    }

    cout << count / 2;
    return 0;
}