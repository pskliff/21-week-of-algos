#include <iostream>
using namespace std;

int trailingZeroes(int n) {
    int count = 0;
    for(unsigned long long i = 5; i <= n; i *= 5)
        count += n / i;
    return count;
}

int main()
{
    int n;
    cin >> n;
    cout << trailingZeroes(n);
    return 0;
}