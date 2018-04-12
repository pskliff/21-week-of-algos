//
// Created by Stas Don on 11/04/2018.
//

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        auto it = nums.begin();
        int prev = *it;
        ++it;
        while(it != nums.end())
        {
            if(*it == prev)
                nums.erase(it);
            else
            {
                prev = *it;
                ++it;
            }
        }
        return nums.size();
    }
};