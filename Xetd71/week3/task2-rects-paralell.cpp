#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;
int main()
{
    const int n = 10;
    pair<int, int> points[n] = {make_pair(1,1), make_pair(1,3), make_pair(1,4), make_pair(2,4), make_pair(3,1),
                                make_pair(3,3), make_pair(3,4), make_pair(4,1), make_pair(4,4), make_pair(5,2)};
    unordered_map<int, unordered_set<int>> hash_points;
    for(auto el : points)
        hash_points[el.first].insert(el.second);

    int count = 0;

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            int first_x= points[i].first;
            int first_y = points[j].second;
            int second_x = points[j].first;
            int second_y = points[i].second;

            // check if recreated points are in hashmap
            if (points[i].first != points[j].first && points[i].second != points[j].second && hash_points.find(first_x) != hash_points.end() && hash_points.find(second_x) != hash_points.end()
                && hash_points[first_x].find(first_y) != hash_points[first_x].end()
                && hash_points[second_x].find(second_y) != hash_points[second_x].end())
            {
                ++count;
//                cout << "First: x = " << points[i].first << "; y = " << points[i].second << endl;
//                cout << "Second: x = " << points[j].first << "; y = " << points[j].second << endl << endl;
//                cout << "Hash second x: " << endl << endl;
            }
        }

    cout << count / 2;
    return 0;
}