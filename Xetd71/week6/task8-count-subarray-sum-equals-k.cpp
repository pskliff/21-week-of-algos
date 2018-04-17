#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int sum = 0, count = 0;
    m[0] = 1;
    for(int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if(m.count(sum - k))
            count += m[sum - k];
        if(m.count(sum))
            ++m[sum];
        else
            m[sum] = 1;
    }
    return count;
}

int main()
{
    vector<int> a({1});
    int k = 0;
    cout << subarraySum(a, k);
    return 0;
}
