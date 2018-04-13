#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("input.txt");
    int n,m;
    fin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    vector<vector<int>> ind(m, vector<int>());

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> arr[i][j];
        }
    }

    fin.close();

    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        int min = arr[i][0];
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] <= min)
            {
                if (arr[i][j] < min)
                    ind[i].clear();
                min = arr[i][j];
                ind[i].emplace_back(j);
            }
        }
    }

    for (int j = 0; j < n; ++j) {
        int max = arr[0][j];
        vector<int> ind_i;
        for (int i = 0; i < m; ++i) {
            if (arr[i][j] >= max) {
                if (arr[i][j] > max)
                    ind_i.clear();
                max = arr[i][j];
                ind_i.emplace_back(i);
            }
        }
        for (int &it : ind_i){
            if (find(ind[it].begin(), ind[it].end(), j) != ind[it].end())
                ++cnt;
    }

}
    cout << cnt<< endl;
    return 0;
}