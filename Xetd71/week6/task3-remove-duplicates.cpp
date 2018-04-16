#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int j = 0;
    for(int i = 0; i < nums.size(); ++i)
        if(nums[i] != nums[j])
            swap(nums[i], nums[++j]);
    return j + (int)(!nums.empty());
}

int main()
{
    int n;
    vector<int> nums;
    for(int i = 0, t; i < n; ++i) {
        cin >> t;
        nums.emplace_back(t);
    }
    cout << removeDuplicates(nums);
    return 0;
}