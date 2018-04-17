#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numb;
    for(int i = 0; i < nums.size(); ++i) {
        if(numb.count(target - nums[i]))
            return vector<int>({numb[target - nums[i]], i});
        numb[nums[i]] = i;
    }
}

int main()
{
    int n, target;
    vector<int> nums;
    cin >> target >> n;
    for(int i = 0, t; i < n; ++i) {
        cin >> t;
        nums.emplace_back(t);
    }
    vector<int> res = twoSum(nums, target);
    cout << res[0] << ' ' << res[1];
    return 0;
}
