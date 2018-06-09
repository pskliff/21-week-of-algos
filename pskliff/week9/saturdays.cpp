#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

int n, r, c;

int countBrigs(vector<int>& people, int& m)
{
    int i = 0, j = 0, cnt = 0;
    while(j < n - 1)
    {
        if (people[j + 1] - people[i] <= m)
            ++j;
        else
            ++i;

        if (j - i + 1 == c)
        {
            cnt++;
            i = j + 1;
            j++;
        }
    }

    return cnt;
}

int binSearch(vector<int>& people)
{
    if (c == 1)
        return 0;

    int left = 0, right = people[people.size() - 1] - people[0];
    while(left < right)
    {
        int m = (left + right) / 2;
        int cnt = countBrigs(people, m);
        if (cnt < r)
            left = m + 1;
        else
            right = m;

    }

    return right;
}


int main()
{
    cin >> n >> r >> c;

    vector<int> people(n);
    for (int i = 0; i < n; ++i)
        cin >> people[i];


    sort(people.begin(), people.end());
    cout << binSearch(people);
    return 0;
}