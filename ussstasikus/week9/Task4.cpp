//
// Created by Stas Don on 02/06/2018.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool isEnough(vector<int> coords, int amount, int min_dist)
{
    int count = 1;
    int coord_num = 1, prev_coord = 0;
    while(count < amount && coord_num < coords.size())
    {
        if(coords[coord_num] - coords[prev_coord] >= min_dist)
        {
            prev_coord = coord_num;
            ++count;
        }
        ++coord_num;
    }
    return count >= amount;
}

int binSearch(vector<int> coords, int amount)
{
    int l = 0, r = coords[coords.size() - 1] - coords[0];

    while(l < r - 1)
    {
        int m = l + (r - l)/2;
        if(isEnough(coords, amount, m))
            l = m;
        else
            r = m - 1;
    }

    if(isEnough(coords, amount, r))
        return r;
    return l;

}

int main()
{
    ifstream fin("input.txt");
    int n, k;
    fin >> n >> k;
    vector<int> coords(n);
    for (int i = 0; i < n; ++i)
        fin >> coords[i];

    ofstream fout("output.txt");
    fout << binSearch(coords, k);
}


