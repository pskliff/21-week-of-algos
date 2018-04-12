#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("input.txt", std::ios::in);
    ofstream fout("output.txt", std::ios::out);

    size_t n, m;
    fin >> n >> m;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; ++i)
        fin >> a[i];
    for (int j = 0; j < m; ++j)
        fin >> b[j];

    size_t i = 0, j = 0, dif = static_cast<size_t>(abs(a[0] - b[0]));

    while (i < a.size() || j < b.size())
    {
        if (a[i] > b[j])
            if (j >= b.size() - 1)
                break;
            else
                ++j;
        else if (a[i] == b[j])
        {
            dif = 0;
            break;
        }
        else if (i >= a.size() - 1)
            break;
        else
            ++i;
        if (abs(a[i] - b[j]) < dif)
            dif = static_cast<size_t>(abs(a[i] - b[j]));
    }

    fout << dif;

    fin.close();
    fout.close();

    return 0;
}