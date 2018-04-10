#include<fstream>
#include<vector>

using namespace std;

const int NMAX = 750, MMAX = 750;
int a[NMAX][MMAX];

int main()
{
    ifstream fin("input.txt", std::ios::in);
    ofstream fout("output.txt", std::ios::out);

    int n, m;
    fin >> n >> m;
    vector<int> min_rows(n, 1001), max_cols(m, -1001);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            fin >> a[i][j];
            if (a[i][j] < min_rows[i])
                min_rows[i] = a[i][j];
            if (a[i][j] > max_cols[j])
                max_cols[j] = a[i][j];
        }

    int count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == min_rows[i] && a[i][j] == max_cols[j])
                ++count;
        }

    fout << count;

    fin.close();
    fout.close();

    return 0;
}