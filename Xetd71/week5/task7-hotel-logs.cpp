#include<iostream>
using namespace std;

int main()
{
    const int DAY_MAX = 365;
    int n, logs[DAY_MAX];
    for(int i = 0; i < DAY_MAX; ++i)
        logs[i] = 0;
    cin >> n;
    for(int i = 0, st, ed; i < n; ++i) {
        cin >> st >> ed;
        logs[st] += 1;
        logs[ed] -= 1;
    }

    int maxVisitors = 0;
    for(int i = 0, cur = 0; i < DAY_MAX; ++i)
        maxVisitors = max(maxVisitors, cur += logs[i]);
    cout << maxVisitors;
    return 0;
}