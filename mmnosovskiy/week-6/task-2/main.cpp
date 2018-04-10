#include<fstream>
#include<vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> prev_ind;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (prev_ind.find(target - nums[i]) != prev_ind.end())
            return vector<int> {prev_ind[target - nums[i]], i};
        prev_ind[nums[i]] = i;
    }
    return vector<int>();
}

int main()
{
    ifstream fin("input.txt", std::ios::in);
    ofstream fout("output.txt", std::ios::out);

    int n, target;
    fin >> n >> target;
    vector<int> nums;
    int t;
    for (int i = 0; i < n; ++i)
        fin >> t, nums.push_back(t);

    auto res = twoSum(nums, target);

    for (int item : res)
        fout << item << " ";

    fin.close();
    fout.close();

    return 0;
}