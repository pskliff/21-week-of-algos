#include<algorithm>
#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<pair<size_t, size_t>> journal;
    for (int i = 0; i < n; ++i) {
        size_t day_in, day_out;
        cin >> day_in >> day_out;
        journal.emplace_back(make_pair(day_in, day_out));
    }

    int cnt = 0, maxCnt = 0;
    std::vector<std::pair<size_t, size_t>> intervals;
    std::vector<pair<size_t, int>> days;


    for (auto &it : journal) {
        days.emplace_back(it.first, 1);
        days.emplace_back(it.second, -1);
    }
    std::sort(days.begin(), days.end());
    size_t day_in, day_out;
    for (auto &day : days) {
        if (day.second == 1) {
            ++cnt;
            day_in = day.first;
        } else {
            day_out = day.first;
            if (cnt >= maxCnt) {
                if (cnt > maxCnt)
                    intervals.clear();
                maxCnt = cnt;
                intervals.emplace_back(day_in, day_out);

            }
            --cnt;

        }


    }


    for (auto &it : intervals)
        cout << it.first << " - " << it.second << endl;
    return 0;
}


//        ____________________
//       /    _____           \
//      /    /     \           \
//  |---o---o---o---o---|---|---o---|---o---
//  0   1   2   3   4   5   6   7   8   9
//               \_____________________/
//

//
//
//      +   +   +   -           -       -
//  |---o---o---o---o---|---|---o---|---o---
//  0   1   2   3   4   5   6   7   8   9
//
//

