#include <iostream>
#include <string>
using namespace std;

pair<int, int> binarySearch(int* arr, int len, int k)
{
    int l = 0, r = len - 1;
    while(l < r) {
        int m = (l + r) / 2;
        if(arr[m] == k) {
            if(arr[l] != k)
                l = m;
            if(arr[r] != k)
                r = m;
            break;
        } else  if(arr[m] < k) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    if(arr[r] != k)
        return make_pair(-1, -1);
    while(l > 0 && arr[l - 1] == k) --l;
    while(r < len - 1 && arr[r + 1] == k) ++r;
    return make_pair(l, r);
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
        pair<int, int> res = binarySearch(arr, n, el);
        if(res.first == - 1)
            cout << "0\n";
        else
            printf("%d %d\n", res.first + 1, res.second + 1);
    }
    delete[] arr;
    return 0;
}