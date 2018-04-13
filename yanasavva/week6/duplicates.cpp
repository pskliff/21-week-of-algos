#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("input.txt");
    int n;
    fin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        fin >> arr[i];
    int delta = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[i - 1])
            ++delta;
        else arr[i - delta] = arr[i];
    }

    for (int i = 0; i < n - delta; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\nnew length = " << n - delta << endl;
    return 0;
}