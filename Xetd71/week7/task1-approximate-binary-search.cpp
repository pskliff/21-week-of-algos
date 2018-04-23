#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMin(int* arr, int n, int k) {
    int l = 0,  r = n - 1;
    while(l < r) {
        int m = (l + r) / 2;
        if(arr[m] < k)
            l = m + 1;
        else
            r = m;
    }
    return arr[(l == 0 || abs(arr[l - 1] - k) > abs(arr[l] - k) ? l : l - 1)];
}

int* getMins(int* a, int lenA, int* b, int lenB) {
    int* res = new int[lenB];
    for(int i = 0; i < lenB; ++i)
        res[i] = findMin(a, lenA, b[i]);
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int* a, * b, * res, lenA, lenB;
    cin >> lenA >> lenB;
    a = new int[lenA];
    for(int i = 0; i < lenA; ++i)
        cin >> a[i];
    b = new int[lenB];
    for(int i = 0; i < lenB; ++i)
        cin >> b[i];
    res = getMins(a, lenA, b, lenB);
    for(int i = 0; i < lenB; ++i)
        cout << res[i] << '\n';
    delete[] a;
    delete[] b;
    delete[] res;
    return 0;
}