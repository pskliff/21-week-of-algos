#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long double arr[n], sum = 0, k, t;
    for(int i = 0; i < n; ++i) {
        cin >> k >> t;
        arr[i] = k * t;
        sum += arr[i];
    }

    cout.precision(12);
    for(int i = 0; i < n; ++i)
        cout << arr[i] / sum << endl;
    return 0;
}