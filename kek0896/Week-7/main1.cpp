#include <fstream>
#include <vector>

// part solution - does not pass 4th test (all rest are OK)

using namespace std;

int binsearch(vector<int> &a, int curr, int l, int h){

    while (l < h - 1)
    {
        int mid = (l + h) / 2;
        if (a[mid] == curr) return a[mid];
        if (a[mid] < curr) l = mid;
        else h = mid;
    }
    return (abs(a[l] - curr) <= abs(a[h] - curr)) ? a[l] : a[h];

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