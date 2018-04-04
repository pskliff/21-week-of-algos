//
// Created by Stas Don on 02/04/2018.
//
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int curr_index = 0;
    for (int i = 0; i < n; ++i) {
        if(nums[i] != 0)
            nums[curr_index++] = nums[i];
    }
    for (int i = curr_index; i < n; ++i) {
        nums[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        cout << nums[i];
    }
}