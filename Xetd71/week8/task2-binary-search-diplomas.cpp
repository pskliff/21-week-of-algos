#include <iostream>
using namespace std;

long long getRectLen(long long w, long long h, long long n)
{
    long long l, r, m;
    if(w < h)
        l = w, r = h * n;
    else
        l = h, r = w * n;

    while(l < r) {
        m = (r + l) / 2;
        if((m / w) * (m / h) < n)
            l = m + 1;
        else
            r = m;
    }
    return r;
}

int main()
{
    long long w, h, n;
    cin >> w >> h >> n;
    cout << getRectLen(w, h, n);
    return 0;
}