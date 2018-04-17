#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int> a, vector<int> b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int min_abs = INT32_MAX;
    int i = 0, j = 0;
    int n = a.size(), m = b.size();
    while(i < n && j < m){
        int buf = abs(a[i] - b[j]);
        min_abs = buf < min_abs ? buf : min_abs;
        if(a[i] < b[j]){
            ++i;
            continue;
        }
        if(a[i] >= b[j]){
            ++j;
            continue;
        }
    }
    while(i < n)
    {
        int buf = abs(a[i] - b[j - 1]);
        min_abs = buf < min_abs ? buf : min_abs;
        ++i;
    }
    while(j < m)
    {
        int buf = abs(a[i - 1] - b[j]);
        min_abs = buf < min_abs ? buf : min_abs;
        ++j;
    }

    return min_abs;
}

int main()
{
    int arr1[] = {1, 2 ,3,4};
    int arr2[] = {11, 22, 10};
    vector<int> nums1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
    vector<int> nums2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
    cout << findMin(nums1, nums2);
    return 0;
}