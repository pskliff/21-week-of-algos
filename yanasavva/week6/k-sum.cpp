#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    unordered_map<int, pair<int,int>> pref_sum;

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int numb;
        cin >> numb;
        sum += numb;
        if(pref_sum.find(sum) == pref_sum.end())
        {
            pref_sum[sum] = make_pair(i + 1, -1);
        }
        if(pref_sum.find(sum - k) != pref_sum.end())
            pref_sum[sum - k].second = i;

    }
    for (auto &it : pref_sum)
    {
        if (it.second.second != -1)
            cout << it.second.first << " - " << it.second.second << endl;
    }
    return 0;
}

