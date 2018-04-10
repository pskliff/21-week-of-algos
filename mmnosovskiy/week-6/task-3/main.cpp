#include<fstream>
#include<vector>
#include <unordered_map>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int prev = nums[0], count_rem = 0;
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] == prev)
            ++count_rem;
        else
            nums[i - count_rem] = prev = nums[i];
    }
    return nums.size() - count_rem;
}

int main()
{
    ifstream fin("input.txt", std::ios::in);
    ofstream fout("output.txt", std::ios::out);

    int n;
    fin >> n;
    vector<int> nums;
    int t;
    for (int i = 0; i < n; ++i)
        fin >> t, nums.push_back(t);

    int res = removeDuplicates(nums);

    fout << res << "\n";
    for (int i = 0; i < res; ++i)
        fout << nums[i] << " ";

    fin.close();
    fout.close();

    return 0;
}