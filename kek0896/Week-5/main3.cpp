#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n;

    ifstream fin;
    fin.open("input.txt");
    fin >> n;
    int zeroones[n];
    for (int i = 0; i < n; i++) fin >> zeroones[i];
    fin.close();

    int i = 0, res = 0;
    int c1 = 0, c2 = 0, zer = 0;

    while(i < n)
    {

        while (i < n && zeroones[i] == 0)
        { zer++; i++; }

        while (i < n && zeroones[i] == 1)
        { c2++; i++; }

        if(zer > 1) res = max(res, max(c1, c2));
        else res = max(res, c1 + c2);

        c1 = c2; c2 = 0; zer = 0;

    }

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res;
    fout.close();

    return 0;
}