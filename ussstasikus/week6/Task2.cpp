//
// Created by Stas Don on 11/04/2018.
//

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ns;
        for(auto n: nums)
        {
            if(ns.find(n) == ns.end())
                ns[n] = 1;
            else
                ns[n] += 1;
        }

        int first_val, second_val;
        for(auto n = ns.begin(); n != ns.end(); ++n)
        {
            n->second -= 1;
            if(ns.find(target - n->first) != ns.end() && ns[target - n->first] != 0)
            {
                first_val = n->first;
                second_val = target - n->first;
                break;
            }

            n->second += 1;
        }

        vector<int> inds(2, -1);
        for(int i = 0; i < nums.size(); ++i)
        {
            if(inds[0] != -1 && inds[1] != -1)
                return inds;
            if(inds[0] == -1 && nums[i] == first_val)
                inds[0] = i;
            else if(inds[1] == -1 && nums[i] == second_val)
                inds[1] = i;
        }
        return inds;
    }
};