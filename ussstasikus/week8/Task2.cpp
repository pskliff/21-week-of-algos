//
// Created by Stas Don on 29/04/2018.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isSuits(long long a, long long n, long long h, long long w)
{
    return n <= (a / h) * (a / w);
}


long long findSmallestSquare(long long h, long long w, long long n)
{
    long long l = min(h, w), r = n * max(h, w);

    while(l < r)
    {
        long long middle = l + (r - l)/2;
        if(isSuits(middle, n, h, w))
            r = middle;
        else
            l = middle + 1;
    }
    return r;
}



int main()
{
    ifstream fin("input.txt");
    long long h, w, n;
    fin >> h >> w >> n;

    ofstream fout("output.txt");
    fout << findSmallestSquare(h, w, n);



}