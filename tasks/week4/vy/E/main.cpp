#include <iostream>

using namespace std;

typedef unsigned long long ull;

const ull INF = 1e10;

ull nextDay(ull x, ull m) {
	if (x > m)
		return 0;
	ull l = x, r = INF;
	while (l + 1 < r) {
		ull mid = (l + r) / 2;
		ull cnt = (x + mid) * (mid - x + 1) / 2;
		if (cnt <= m)
			l = mid;
		else
			r = mid;
	}
	return l;
}

int main() {
	ull k, m, d, x = 1;
	cin >> k >> m >> d;
	--d;
	while (true) {
		// cout << "STEP" << endl;
		if ((d + x - 1) % 7 < 5)
			m += k;
		ull nxt = nextDay(x, m);
		// cout << "NXT " << nxt << endl;
		if (nxt == 0)
			break;
		//cout << "POTRAT " << (x + nxt) * (nxt - x + 1) / 2 << endl;
		m -= (x + nxt) * (nxt - x + 1) / 2;
		ull p = (nxt - x);
		ull s = p / 7 * 5;
		for (ull cur = nxt; (cur - x) % 7 > 0; --cur)
			if ((d + cur - 1) % 7 < 5)
				++s;
		m += k * s;
		x = nxt + 1;
	}
	cout << x - 1 << endl;
	cin >> x;
	return 0;
}