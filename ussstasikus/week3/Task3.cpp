//
// Created by Stas Don on 29/03/2018.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int howManyRectsInARow(int n) {
    return n*(n + 1)/2;
}

struct CompX {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};


struct CompY{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if(a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
};


int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);

    set<pair<int, int>, CompX> sort_x;
    set<pair<int, int>, CompY> sort_y;
//    map<int, int, CompX> sort_x;
//    map<int, int, CompY> sort_y;


    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
//        sort_x[x] = y;
//        sort_y[x] = y;
        sort_x.insert({x, y});
        sort_y.insert({x, y});
    }

//    for(auto p: sort_x)
//        cout << p.first << " " << p.second << endl;
//    cout<<endl;
//
//    for(auto p: sort_y)
//        cout << p.first << " " << p.second << endl;
//
//    auto test = sort_y.find({4, 1});
//    cout<<endl<<test->first << " " << test->second;
//    ++test;
//    cout<<endl<<test->first << " " << test->second;
//    ++test;
//    cout<<endl<<test->first << " " << test->second;
//    ++test;
//    cout<<endl<<test->first << " " << test->second;


    int general_count = 0;

    for(auto point = sort_x.begin(); point != sort_x.end() && point != sort_y.end() ;)
    {
//        cout<<"ENTERED: " << point->first << " " << point->second << endl;

        auto eq_x = ++sort_x.find({point->first, point->second});
        auto eq_y_start = ++sort_y.find({point->first, point->second});

        auto eq_y = eq_y_start;

        int count = 0;

        while(eq_x != sort_x.end() &&  eq_x->first == point->first)
        {
//            cout<<"EQ_X: " << eq_x->first << " " << eq_x->second << endl;

            eq_y = eq_y_start;
            while(eq_y != sort_y.end() &&  eq_y->second == point->second)
            {
//                cout<<"EQ_Y: " << eq_y->first << " " << eq_y->second << endl;
                if(sort_x.find({eq_y->first, eq_x->second}) != sort_x.end())
                {
                    ++count;
                }
                ++eq_y;
            }
            ++eq_x;
        }
        point = eq_y;
        general_count += howManyRectsInARow(count);
    }

    cout << general_count;


}
