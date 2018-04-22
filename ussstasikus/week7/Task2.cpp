//
// Created by Stas Don on 21/04/2018.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


bool binSearch(int n, const vector<long> &array)
{
    int l = 0, r = array.size() - 1;
    while(r > l)
    {
        int middle = (r + l) / 2;
        if(array[middle] == n)
        {
            l = middle;
            break;
        }
        else if(array[middle] > n)
            r = middle - 1;
        else if(array[middle] < n)
            l = middle + 1;
    }

    return array[l] == n;
}

void KNearestNumbers(const vector<long> &a, const vector<long> &b)
{
    ofstream fout("output.txt");
    for(auto n: b)
        fout << (binSearch(n, a) ? "YES" : "NO") << endl;
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

}