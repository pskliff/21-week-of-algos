#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    string t, p;
    cin >> t >> p;
    int sum = 0;
    unordered_set<int> set;
    for (int i = 0; i < p.length(); ++i) {
        set.emplace(p[i]);
        sum += p[i];
    }

    int n = t.length()+p.length();
    for (int i = 0; i < t.length() - p.length() + 1; ++i) {
        int j = 0, tmp_sum = sum;
        for ( ; j < p.length(); ++j)
        {
            cout << n-- << " ";
            if (set.find(t[i + j]) == set.end())
            {
                i += j;
                break;
            }
            tmp_sum -= t[i + j];
        }
        if (tmp_sum == 0)
        {
            cout << "start index - " << i;
            return 0;
        }
    }
    cout << "no matching";

    return 0;
}

