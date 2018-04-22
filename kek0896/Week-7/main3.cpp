//
// Created by Маргарита Мариампиллай on 21.04.2018.
//
#include <fstream>
#include <vector>

using namespace std;

string binsearch(vector<int> &a, int curr, int l, int h){
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (a[mid] == curr)
        {
            int p1 = mid, p2 = mid;
            while(p1 > 0 && a[p1 - 1] == curr) p1--;
            while(p2 + 1 < a.size() && a[p2 + 1] == curr) p2++;
            return to_string(p1 + 1) + " " + to_string(p2 + 1);
        }
        if (a[mid] < curr) l = mid + 1;
        else h = mid - 1;
    }
    return "0";
}

int main()
{

    ifstream fin("input.txt");
    int n, k;
    fin >> n >> k;

    vector<int> a(n), b(k);

    for (int i = 0; i < n; ++i) fin >> a[i];
    for (int j = 0; j < k; ++j) fin >> b[j];
    fin.close();

    ofstream fout("output.txt");
    for(auto i : b)
        fout << binsearch(a, i, 0, n - 1) << endl;
    fout.close();

    return 0;
}