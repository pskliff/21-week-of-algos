#include <iostream>
using namespace std;

bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;
}

int main()
{
    int n;
    cin >> n;
    cout << isPowerOfThree(n);
    return 0;
}