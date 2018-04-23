#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>> g) {
    int n = g.size();
    int* sides = new int[n];
    for(int i = 0; i < n; ++i)
        sides[i] = -1;

    for(int i = 0; i < n; ++i) {
        if(sides[i] != -1)
            continue;
        sides[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int el = q.front();
            q.pop();
            for(int& j : g[el]) {
                if(sides[j] != -1) {
                    if(sides[j] == sides[el])
                        return false;
                } else {
                    sides[j] = sides[el] ^ 1;
                    q.push(j);
                }
            }
        }
    }

    delete[] sides;
    return true;
}

int main()
{
    vector<vector<int>> g({{1,5,8},{0,2,4},{1,4,6,9},{4},{1,2,3,8},{0},{2,7},{6},{0,4},{2}});
    cout << isBipartite(g);
    return 0;
}