#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int min = abs(arr1[0] - arr2[0]);
    for(int i = 0, j = 0; i < n && j < m;)
    {
        int dif = abs(arr1[i] - arr2[j]);
        if (dif == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        if (dif < min)
            min = dif;
        if(arr1[i] < arr2[j])
            ++i;
        else ++j;
        if (i - j > 1)
            ++j;
        if(j - i > 1)
            ++i;
    }

    cout << min << endl;

    return 0;
}

