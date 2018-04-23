#include <iostream>
#include <string>
using namespace std;

bool binarySearch(int* arr, int len, int k)
{
    int l = 0, r = len - 1;
    while(l < r) {
        int m = (l + r) / 2;
        if(arr[m] < k)
            l = m + 1;
        else if(arr[m] > k)
            r = m - 1;
        else
            return true;
    }
    return arr[r] == k;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int* arr = new int[n];
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    for(int i = 0, el; i < k; ++i) {
        cin >> el;
        cout << (binarySearch(arr, n, el) ? "YES\n" : "NO\n");
    }
    delete[] arr;
    return 0;
}