//
// Created by Stas Don on 21/04/2018.
//
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int binSearch(int n, const vector<int> &array)
{
    int l = 0, r = array.size() - 1;
    while(r - l > 1)
    {
        int middle = (r + l) / 2;
        if(array[middle] == n)
        {
            l = middle;
            break;
        }
        else if(array[middle] > n)
            r = middle;
        else if(array[middle] < n)
            l = middle;
    }

    return (n - array[l] > array[r] - n) ? array[r] : array[l];
}

void KNearestNumbers(const vector<int> &a, const vector<int> &b)
{
    ofstream fout("output.txt");
    for(auto n: b)
        fout << binSearch(n, a) << endl;
}


int main()
{
    int N, K;
    ifstream fin("input.txt");
    fin >> N >> K;

    vector<int> a(N), b(K);

    for (int i = 0; i < N; ++i)
        fin >> a[i];

    for (int i = 0; i < K; ++i)
        fin >> b[i];

    KNearestNumbers(a, b);

}