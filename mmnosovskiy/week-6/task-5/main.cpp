#include<fstream>
#include<vector>
#include <unordered_map>

using namespace std;

int main()
{
    ifstream fin("input.txt", std::ios::in);
    ofstream fout("output.txt", std::ios::out);

    int n;
    fin >> n;

    int a[n];
    for (int i = 0; i < n; ++i)
        fin >> a[i];

    vector<string> res;

    int start = a[0];
    for (int i = 1; i < n + 1; ++i)
    {
        if (i == n || a[i] != a[i - 1] + 1)
        {
            if (start == a[i - 1])
                res.push_back(to_string(start));
            else
                res.push_back(to_string(start) + "-" + to_string(a[i - 1]));
            start = a[i];
        }
    }

    for (const auto &item : res)
        fout << item << " ";

    fin.close();
    fout.close();

    return 0;
}