#include <iostream>

using namespace std;

int main()
{
    unsigned long long k, m, d, now = 1;
    cin >> k >> m >> d;
    --d;
    while (true) {
        if ((d + now - 1) % 7 < 5)
            m += k;

        if (now > m)
            break;

        unsigned long long nxt = now, tmp = 1e10;
        while (nxt + 1 < tmp) {
            unsigned long long mid = (nxt + tmp) / 2;
            unsigned long long cnt = (now + mid) * (mid - now + 1) / 2;
            if (cnt <= m)
                nxt = mid;
            else
                tmp = mid;
        }

        unsigned long long n = (nxt - now) / 7 * 5;
        for (unsigned long long i = nxt; (i - now) % 7 > 0; --i)
            if ((d + i - 1) % 7 < 5)
                ++n;
        m += n * k - (now + nxt) * (nxt - now + 1) / 2;
        now = nxt + 1;
    }
    cout << now - 1;
    return 0;
}