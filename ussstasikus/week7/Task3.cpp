//
// Created by Stas Don on 21/04/2018.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int binSearchLeft(int n,  vector<long> array, ofstream &fout)
{
    int l = 0, r = array.size() - 1;

    while(r > l)
    {
        int middle = (r + l) / 2;
        if(array[middle] >= n)
            r = middle - 1;
        else if(array[middle] < n)
            l = middle + 1;
    }

    return array[r] > n ? r - 1 : r;
}


int binSearchRight(int n, vector<long> array, ofstream &fout)
{
    int l = 0, r = array.size() - 1;

    while(r > l)
    {
        int middle = (r + l) / 2;
        if(array[middle] > n)
            r = middle - 1;
        else if(array[middle] <= n)
            l = middle + 1;
    }
    return array[l] < n ? l + 1 : l;
}


void KNearestNumbers(const vector<long> &a, const vector<long> &b)
{

    ofstream fout("output.txt");
    for(auto n: b)
    {
        int next  = binSearchLeft(n + 1, a, fout);
        int prev = binSearchRight(n - 1, a, fout);

        int start = a[prev] == n ? prev : prev + 1;
        int last = a[next] == n ? next : next - 1;

        if (start >= a.size() || a[start] != n)
            fout << 0 << endl;
        else
            fout << start + 1 << " " << last + 1 << endl;
    }
    fout.close();
}


int main()
{
    int N, K;
    ifstream fin("input.txt");
    fin >> N >> K;

    vector<long> a(N), b(K);

    for (int i = 0; i < N; ++i)
        fin >> a[i];

    for (int i = 0; i < K; ++i)
        fin >> b[i];

    KNearestNumbers(a, b);
    fin.close();
}