#include <iostream>

using namespace std;

int main()
{
    string s1 = "aaaaaa", s2 = " !01BbZz", res = "";
    bool was[256] = {false};

    for (int i = 0; i < s2.length(); ++i)
    {
        cout << (int)s2[i] << endl;
        cout << ((int)s2[i] + 128) << endl;
        was[s2[i] + 128] = true;
    }


    for (int i = 0; i < s1.length(); ++i)
        if(!was[s1[i] + 128])
            res += s1[i];

    cout << (res == "" ? "-1" : res);
    return 0;
}


//  void moveZeroes(vector<int>& nums) {
//         for(int curr = 0, lst = 0; curr < nums.size(); ++curr)
//             if(nums[curr])
//                 swap(nums[lst++], nums[curr]);
//     }

