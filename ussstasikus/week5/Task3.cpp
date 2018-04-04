//
// Created by Stas Don on 02/04/2018.
//

#include <iostream>
#include <vector>

using namespace std;

int maxLenOfOnes(vector<int> arr)
{
    int n1 = 0, n2 = 0, n_max = 0;
    int index_of_zero = 0;

    for (int i = 0; i < arr.size(); ++i) {
        if(arr[i] == 0)
        {
            n2 = 0;
            int j = i;
            while (arr[j + 1] != 0 && j + 1 < arr.size()) {
                n2 += 1;
                ++j;
            }

            if(n1 + n2 > n_max)
                n_max = n1 + n2;

            n1 = n2;
            i = j;
        }
        else
        {
            ++n1;
        }
    }
    if(n1 > n_max)
        n_max = n1 + n2;
    return n_max;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << maxLenOfOnes(arr);
}
//16
//1 0 1 1 1 0 0 1 1 0 1 1 1 1 0 1
