#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("input.txt");
    int n;
    fin >> n;
    int arr[n];
    vector<string> res;
    for (int i = 0; i < n; ++i)
        fin >> arr[i];
    fin.close();
    int i = 1;
    string s = "";
    while (i <= n)
    {
        s = to_string(arr[i - 1]);
        int j = i;
        while(i < n && arr[i - 1] == arr[i] - 1)
            ++i;
        if (i > j)
            s += '-' + to_string(arr[i - 1]);
        res.emplace_back(s);
        ++i;
    }

    for (auto &it : res)
        cout << it << " ";

    return 0;
}