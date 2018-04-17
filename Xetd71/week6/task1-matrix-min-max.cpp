#include <iostream>
#include <limits.h>
using namespace std;

int minMaxCount(int** arr, int n, int m)
{
    int* minRow = new int[n];
    int* maxColumn = new int[m];
    for(int i = 0; i < n; ++i)
        minRow[i] = INT16_MAX;
    for(int j = 0; j < m; ++j)
        maxColumn[j] = INT16_MIN;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(minRow[i] > arr[i][j])
                minRow[i] = arr[i][j];
            if(maxColumn[j] < arr[i][j])
                maxColumn[j] = arr[i][j];
        }
    }

    int count = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(minRow[i] == arr[i][j] && maxColumn[j] == arr[i][j]) {
                ++count;
            }
        }
    }

    delete[] minRow;
    delete[] maxColumn;
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int** arr = new int*[n];
    for(int i = 0; i < n; ++i)
        arr[i] = new int[m];

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> arr[i][j];
    cout << minMaxCount(arr, n, m);

    for(int i = 0; i < n; ++i)
        delete[] arr[i];
    delete[] arr;
    return 0;
}