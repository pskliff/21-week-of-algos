#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> collapseArray(int* arr, int n) {
    vector<string> res;
    int j = 0;
    for(int i = 1; i < n; ++i) {
        if(arr[i] != arr[i - 1] + 1) {
            res.emplace_back(to_string(arr[j]) + (i - 1 == j ? "" : '-' + to_string(arr[i - 1])));
            j = i;
        }
    }
    res.emplace_back(to_string(arr[j]) + (n - 1 == j ? "" : '-' + to_string(arr[n - 1])));
    return res;
}


int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    for(string& s : collapseArray(arr, n))
        cout << s << ' ';
    delete[] arr;
    return 0;
}