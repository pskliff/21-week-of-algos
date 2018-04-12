#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.count(target - nums[i]))
            return { m[target - nums[i]], i };
        m[nums[i]] = i;
    }
}

int main()
{
    ifstream fin;
    fin.open("input.txt");

    size_t n;
    fin >> n; // numb of elems, elems and then target
    int target;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) fin >> arr[i];
    fin >> target;
    fin.close();

    vector<int> res = twoSum(arr, target);

    fstream fout;
    fout.open("output.txt", ios::out);
    for (auto j : res)
        fout << j << " ";
    fout.close();

    return 0;
}

//// submitted

//#include <unordered_map>
//class Solution {
//public:
//    vector<int> twoSum(vector<int> &nums, int target)
//    {
//        unordered_map<int, int> m;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (m.count(target - nums[i]))
//                return { m[target - nums[i]], i };
//            m[nums[i]] = i;
//        }
//    }
//};