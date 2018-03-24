#include <iostream>

using namespace std;

typedef long double ld;

const int MAXN = 1e2;
int n;
ld c[MAXN], sumc = 0;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ld a, b;
		cin >> a >> b;
		sumc += (c[i] = (a / 100) * (b / 100));
	}
	cout.precision(10);
	cout << fixed;
	for (int i = 0; i < n; ++i)
		cout << c[i] / sumc << endl;
	cin >> n;
	return 0;
}