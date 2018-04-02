//
// Created by Stas Don on 02/04/2018.
//
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int curr_index = 0;
    for (int i = 0; i < n; ++i) {
        if(arr[i] != 0)
            arr[curr_index++] = arr[i];
    }
    for (int i = curr_index; i < n; ++i) {
        arr[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        cout << arr[i];
    }
}