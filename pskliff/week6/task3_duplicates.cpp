#include <iostream>
#include <vector>

using namespace std;


int removeDuplicates(vector<int>& nums)
{
    int count = 0;
    int sz = nums.size();
    int lst = 0;
    if (sz == 0)
        return 0;
    for (int curr = 0; curr < nums.size(); ++curr)
    {
        if (nums[curr] != nums[lst])
        {
            swap(nums[++lst], nums[curr]);
            ++count;
        }
    }

//    count = count == 0 ? 1 : count;
//    nums.resize(count + 1);
//    for (auto el : nums)
//    {
//        cout << el << " ";
//    }
//    cout << endl;
    return count + 1;
}


int main()
{
    int arr[] = {1, 2};
//    int arr[] = {1, 2, 2, 5, 5, 5, 6};
//    int arr[] = {1, 2,3 ,4 };
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    cout << endl << removeDuplicates(nums);
    return 0;
}