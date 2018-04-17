#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;

int arraysMinDistance(vector<int>& a, vector<int>& b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a[0] > b[0])
        swap(a, b);
    int minDis = INT_MAX;
    int i = 0, j = 0, n = a.size(), m = b.size();
    while(i < n && j < m) {
        while(i + 1 < n && a[i + 1] <= b[j]) ++i;
        minDis = min(minDis, abs(a[i] - b[j]));
        ++i;
        while(j + 1 < m && b[j + 1] <= a[i]) ++j;
        minDis = min(minDis, abs(a[i] - b[j]));
        ++j;
    }
    return minDis;
}

int main()
{
    vector<int> a({1, 4});
    vector<int> b({3});
    cout << arraysMinDistance(a, b);
    return 0;
}
