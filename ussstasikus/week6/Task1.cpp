//
// Created by Stas Don on 11/04/2018.
//
#include <iostream>
#include <vector>

using namespace std;

int howMuchSedlovieTochki(vector<vector<int>> &matrix) {
    size_t N = matrix.size(), M = matrix[0].size();
    vector<int> min_rows(N, INT16_MAX);
    vector<int> max_col(M, -INT16_MAX);


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (matrix[i][j] < min_rows[i])
                min_rows[i] = matrix[i][j];
            if (matrix[i][j] > max_col[j])
                max_col[j] = matrix[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (matrix[i][j] == min_rows[i] && matrix[i][j] == max_col[j])
                ++count;
        }
    }
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n,vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << howMuchSedlovieTochki(matrix);
}
