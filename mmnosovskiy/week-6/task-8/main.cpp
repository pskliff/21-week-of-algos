#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("input.txt", std::ios::in);
    ofstream fout("output.txt", std::ios::out);

    int n, k;
    fin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i)
        fin >> a[i];

    int sum = 0, start = -1, end = -1;
    unordered_map<int, vector<int>> sub_sums;
    for (int i = 0; i < n; ++i)
    {
        sum += a[i];
        sub_sums[sum].push_back(i);
    }
    auto it = sub_sums.begin();
    while (it != sub_sums.end())
    {
        int a1 = it->first;
        if (sub_sums.find(a1 + k) != sub_sums.end())
        {
            int start1, end1, start2, end2, start3, end3;
            start1 = sub_sums[a1].front();
            end1 = sub_sums[a1].back();
            start2 = sub_sums[a1 + k].front();
            end2 = sub_sums[a1 + k].back();
            if (start1 < start2)
                start3 = start1, end3 = end2;
            else
                start3 = start2, end3 = end1;
            if (end3 - start3 > end - start)
                end = end3, start = start3;
        }
        ++it;
    }

    while (start >= 0 && a[start] == 0)
        --start;

    fout << to_string(start + 1) << "->" << to_string(end);

    fin.close();
    fout.close();

    return 0;
}