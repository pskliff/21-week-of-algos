//
// Created by Stas Don on 26/03/2018.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Comparator
{
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
        if(p1.first == p2.first)
            return p1.second > p2.second;
        return p1.first > p2.first;
    }
};

void rebalance(set<pair<int, int>, Comparator> &diff, vector<pair<int, int>> &students)
{
    int n = diff.size();
    int polza = 0, count = 0;
    for(auto p: diff)
    {
        if(count < n/2)
            polza += students[p.second].first;
        else
            polza += students[p.second].second;
        ++count;
    }

    cout << polza << endl;
}


int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> students(n);
    set<pair<int, int>, Comparator> diff;

    int polza = 0;

    for (int i = 0; i < n; ++i) {
        int skill_a;
        cin >> skill_a;
        students[i].first = skill_a;
    }
    for (int i = 0; i < n; ++i) {
        int skill_b;
        cin >> skill_b;
        students[i].second = skill_b;
        diff.insert({students[i].first - students[i].second, i});
    }



    int n_cert;
    cin >> n_cert;

    for (int i = 0; i < n_cert; ++i) {
        int id, type, level_up;
        cin >> id >> type >> level_up;

        auto st = diff.find({students[id - 1].first - students[id - 1].second, id - 1});
        diff.erase(st);

        if(type == 1)
            students[id - 1].first += level_up;
        else
            students[id - 1].second += level_up;

        diff.insert({students[id - 1].first - students[id - 1].second, id - 1});
        rebalance(diff, students);
    }
}

//4
//7 15 3 4
//10 10 0 6
//3
//1 1 4
//4 1 6
//2 2 10