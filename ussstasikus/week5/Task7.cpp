//
// Created by Stas Don on 03/04/2018.
//

#include <iostream>
#include <vector>

using namespace std;

int dayMax(const vector<pair<int, int>> &log)
{
    vector<int> days_fill(365, 0);
    for(auto l: log)
    {
        for (int i = l.first; i <= l.second ; ++i)
            days_fill[i - 1] += 1;
    }

    int max = 0;

    for (int i = 1; i < days_fill.size(); ++i) {
        if(days_fill[i] > days_fill[max])
            max = i;
    }
    return max + 1;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> log(n);

    for (int i = 0; i < n; ++i) {
        int d_in, d_out;
        cin >> d_in >> d_out;
        log[i] = {d_in, d_out};
    }

    cout << dayMax(log);
}