#include <unordered_map>
#include <fstream>
#include <vector>

using namespace std;

// (no, it's not mine - my solution wasn't cool)

int subarraySum(vector<int> &nums, int k)
{
    int sum_curr = 0, cnt = 0;
    unordered_map<int, int> rec;
    rec[0] = 1;
    for (int num : nums)
    {
        sum_curr += num;
        cnt += rec[sum_curr - k];
        rec[sum_curr]++;
    }
    return cnt;
}

int main()
{
    int n, target;

    ifstream fin("input.txt");

    fin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        fin >> arr[i];
    fin.close();

    int res = subarraySum(arr, target);
    ofstream fout("output.txt", std::ios::out);
    fout << res;
    fout.close();

}