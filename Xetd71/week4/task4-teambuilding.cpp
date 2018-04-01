#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k = 0;
const int nMax = 5000;
int know[nMax][nMax];
char group[nMax];

bool setGroup(int el, int g) {
    queue<int> q;
    q.push(el);
    k += group[el] = g;
    int cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int j = 0; j < n; ++j) {
            if (j != cur && !know[cur][j]) {
                if (group[j] != -1) {
                    if (group[j] == group[cur])
                        return false;
                } else {
                    k += group[j] = group[cur] ^ 1;
                    q.push(j);
                }
            }
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 0, v1, v2; i < m; ++i) {
        cin >> v1 >> v2;
        --v1, --v2;
        know[v1][v2] = know[v2][v1] = true;
    }

    for (int i = 0; i < n; ++i)
        group[i] = -1;

    bool good = true;
    for (int i = 0, g = 0; i < n && good; ++i) {
        if (group[i] == -1) {
            good &= setGroup(i, g);
            g ^= 1;
        }
    }

    if (good) {
        cout << n - k << endl;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                if (group[j] == i)
                    cout << j + 1 << ' ';
            }
            cout << endl;
        }
    } else {
        cout << -1;
    }

    return 0;
}
