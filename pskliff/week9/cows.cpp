#include <iostream>
#include <vector>

using namespace std;

int n, k;

int countCows(vector<int>& st, int m)
{
    int i = 0, j = 0, cnt = 0;
    while ( j < n) // cnt < (k - 1) &&
    {
        j++;

        if (st[j] - st[i] >= m)
        {
            cnt++;
            i = j;
        }


    }
    return cnt + 1;
}

int binSearch(vector<int>& st)
{
    int l = 0, r = st[st.size() - 1] - st[0];
    while(l < r - 1)
    {
        int m = l + (r - l)/2;
        int cnt = countCows(st, m);
        if (cnt >= k)
            l = m;
        else
            r = m - 1;
    }

    if(countCows(st, r) >= k)
        return r;
    return l;
}




int main()
{


    cin >> n >> k;

    vector<int> st(n);
    for (int i = 0; i < n; ++i)
        cin >> st[i];


    cout << binSearch(st);
    return 0;
}