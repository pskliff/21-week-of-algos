#include <iostream>
#include <vector>


using namespace std;


int findSedlos(vector<vector<int>>& matr, int n, int m, vector<int>& min_row, vector<int>& max_cols)
{
    int res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (matr[i][j] == min_row[i] && matr[i][j] == max_cols[j]) ++res;
    return res;
}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matr(n, vector<int>(m));
    vector<int> min_rows(n);
    vector<int> max_cols(m);
    fill(min_rows.begin(), min_rows.end(), INT32_MAX);
    fill(max_cols.begin(), max_cols.end(), INT32_MIN);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matr[i][j];
            if (matr[i][j] < min_rows[i])
                min_rows[i] = matr[i][j];
            if (matr[i][j] > max_cols[j])
                max_cols[j] = matr[i][j];
        }
    }


    cout << findSedlos(matr, n, m, min_rows, max_cols);

    return 0;
}