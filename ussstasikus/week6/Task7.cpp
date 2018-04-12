//
// Created by Stas Don on 11/04/2018.
//

#include <iostream>
#include <vector>

using namespace std;

int minDist(vector<int> a, vector<int> b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int it_a = 0, it_b = 0;
    while(it_a + 1 < a.size() && a[it_a + 1]  < b[it_b])
        ++it_a;
    while(it_b + 1 < b.size() && b[it_b + 1]  < a[it_a])
        ++it_b;

    int min_dist = abs(a[it_a] - b[it_b]);
    while(it_a < a.size() && it_b < b.size())
    {
        if(a[it_a] > b[it_b])
            ++it_b;
        else
            ++it_a;
        if(abs(a[it_a] - b[it_b]) < min_dist)
            min_dist = a[it_a] - b[it_b];
    }
    return min_dist;
}


int main()
{
    vector<int> a = {-1,2,8,14,15,16,19};
    vector<int> b = {-4,-3,2,3,5,9,21,30};
//
//    vector<int> a = {1,3,7,15,31};
//    vector<int> b = {2,5,14,41,42};
    cout << minDist(a, b);
}