#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;


vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> res(2);
    unordered_map<int, int> mapa;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (mapa.find(target - nums[i]) != mapa.end())
        {
            res[0] = mapa[target - nums[i]];
            res[1] = i;
        }
        mapa[nums[i]] = i;
    }

//    cout << res[0] << endl << res[1];
    return res;
}


int main()
{
    int arr[] = {2,5,5,11};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    twoSum(nums, 0);
    return 0;
}