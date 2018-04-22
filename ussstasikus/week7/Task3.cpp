//
// Created by Stas Don on 21/04/2018.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void binSearch(int n, const vector<long> &array, ofstream &fout)
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
    if(array[l] != n)
        fout << 0 << endl;
    else
    {
        int left = l, right = l;
        while(left > 0 && array[left - 1] == array[l])
            --left;
        while(right < array.size() - 1 && array[right + 1] == array[l])
            ++right;

        fout << left + 1 << " " << right + 1 << endl;
    }
}

void KNearestNumbers(const vector<long> &a, const vector<long> &b)
{

    ofstream fout("output.txt");
    for(auto n: b)
        binSearch(n, a, fout);
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