#include <iostream>


using namespace std;

typedef unsigned long long ull;
ull w, h, n;


ull binSearch(ull l, ull r)
{
    while (l < r)
    {
        ull s_len = (l + r) / 2;
        ull h_del = s_len / h;
        ull w_del = s_len / w;

        if (w_del * h_del >= n)
            r = s_len;
        else
            l = s_len + 1;
    }
    return min(l, r);
}


int main()
{

    cin >> w >> h >> n;

    ull res = binSearch(0, 1e18);
    cout << res;
    return 0;
}