#include <iostream>
using namespace std;

void swap(int arr[], int i, int j);

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int cnt = 0;
    for (int i = 0, j = 1; j < n; )
    {
        cout << ++cnt << " ";
        if (arr[i] != 0)
        {
            ++i, ++j;
            continue;
        }
        if (arr[j] == 0)
        {
            ++j;
            continue;
        }
        swap(arr, i, j);
        ++i, ++j;
    }
cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}

void swap(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}