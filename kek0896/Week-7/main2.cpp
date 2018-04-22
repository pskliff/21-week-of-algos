#include <fstream>
#include <vector>

using namespace std;

string binsearch(vector<int> &a, int curr, int l, int h){
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (a[mid] == curr) return "YES";
        if (a[mid] < curr) l = mid + 1;
        else h = mid - 1;
    }
    return "NO";
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

//6 4
//10 2 3 4 5 6
//12 34 56 10