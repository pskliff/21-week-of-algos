#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> shlop(vector<int> arr);

int main()
{
    ifstream fin("input.txt");
    size_t n;
    fin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) fin >> arr[i];
    fin.close();

    vector<string> res = shlop(arr);

    fstream fout("output.txt", ios::out);
    for (auto j : res)
        fout << j << " ";
    fout.close();

    return 0;
}

vector<string> shlop(vector<int> n){

    vector<string> res;
    if(n.empty())
        return res;
    long l = n.size();

    // when you are Rita, you can't just do something simple
    res.push_back(to_string(n[0]));
    int counter = 0;

    for (int i = 1; i < l; ++i)
    {
        if (n[i] != n[i-1] - 1 && n[i] != n[i-1] + 1)
        {
            if(counter > 0) res.back() += "-" + to_string(n[i-1]);
            res.push_back(to_string(n[i]));
            counter = 0;
        } else counter++;
    }

    if ((n[l - 1] == (n[l - 2] - 1)) || (n[l - 1] == n[l - 2] + 1))
        res.back() += "-" + to_string(n[l - 1]);
    return res;

}

// Tests

//4
//2 4 6 8
/* 2 4 6 8 */

//5
//1 3 4 6 8
/* 1 3-4 6 8  */

//15
//1 2 3 6 4 10 7 -1 -2 -3 -4 12 9 8 7
/* 1-3 6 4 10 7 -1--4 12 9-7 */

//11
//6 5 7 8 9 11 12 4 3 2 1
/* 6-5 7-9 11-12 4-2 1 */