#include <fstream>
#include <vector>

using namespace std;

int main()
{

    ifstream fin("input.txt");
    size_t n, m;
    fin >> n >> m;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; ++i)
        fin >> a[i];
    for (int j = 0; j < m; ++j)
        fin >> b[j];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(a.empty() || b.empty())
        return 0;

    size_t p1 = 0, p2 = 0;
    int res = abs(a[p1] - b[p2]);

    while (p1 < a.size() && p2 < b.size())
    {
        if (a[p1] == b[p2])
        {
            res = 0;
            break;
        }

        if (a[p1] > b[p2]) ++p2;
        else ++p1;

        if (abs(a[p1] - b[p2]) < res)
            res = abs(a[p1] - b[p2]);
    }

    fstream fout("output.txt", ios::out);
    fout << res;

    fin.close();
    fout.close();

    return 0;
}

//6 4
//10 2 3 4 5 6
//12 34 56 10