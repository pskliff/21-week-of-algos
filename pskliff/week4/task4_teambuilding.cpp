//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int n , m;
//vector<vector<int>> graph;
//vector<char> part;
//vector<int> parts[2];
//
//bool partition_bfs(int start, int start_part)
//{
//    queue<int> q;
//    parts[part[start] = start_part].push_back(start);
//    q.push(start);
//    while(!q.empty())
//    {
//        int current = q.front();
//        q.pop();
//        for (int i = 0; i < n; ++i)
//        {
//            if(graph[current][i] || current == i)
//                continue;
//            else
//                if(part[i] != -1)
//                {
//                    if (part[i] == part[current])
//                        return false;
//                    else
//                        continue;
//                }
//            part[i] = 1 - part[current];  //(part[cur] == LEFT) ? RIGHT : LEFT;
//            parts[part[i]].push_back(i);
//            q.push(i);
//        }
//    }
//    return true;
//}
//
//int main()
//{
//
//    int curr_part = 0;
//    bool ok = true;
//    int start, finish;
//    cin >> n >> m;
//    graph = vector<vector<int>>(n, vector<int>(n));
//    part = vector<char>(n, -1);
//
//    for (int i = 0; i < m; ++i)
//    {
//        cin >> start >> finish;
//        --start; --finish;
//        graph[start][finish] = graph[finish][start] = true;
//    }
//
//    for (int i = 0; i < n; ++i)
//        if(part[i] == -1)
//        {
//            ok &= partition_bfs(i, curr_part);
//            curr_part = 1 - curr_part;
//        }
//
//
//    if (ok)
//    {
//        cout << parts[0].size() << endl;
//        for (int i = 0; i < parts[0].size(); ++i)
//            cout << parts[0][i] + 1 << " ";
//
//        cout << endl;
//        for (int i = 0; i < parts[1].size(); ++i)
//            cout << parts[1][i] + 1 << " ";
//    } else
//        cout << "-1";
//
//    return 0;
//}





//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//const int MAXN = 5e3;
//const int NONE = -1;
//const int LEFT = 0;
//const int RIGHT = 1;
//
//int n, m, part[MAXN];
//int e[MAXN][MAXN];
//vector <int> parts[2];
//
//bool makePartrition(int start, int startPart) {
//    queue <int> q;
//    parts[part[start] = startPart].push_back(start);
//    q.push(start);
//    while (!q.empty()) {
//        int cur = q.front();
//        q.pop();
//        for (int i = 0; i < n; ++i) {
//            if (i == cur || e[i][cur])
//                continue;
//            if (part[i] != NONE) {
//                if (part[i] == part[cur])
//                    return false;
//                else
//                    continue;
//            }
//            int p = (part[cur] == LEFT) ? RIGHT : LEFT;
//            parts[part[i] = p].push_back(i);
//            q.push(i);
//        }
//    }
//    return true;
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin >> n >> m;
//    for (int i = 0; i < m; ++i) {
//        int u, v;
//        cin >> u >> v;
//        --u, --v;
//        e[u][v] = e[v][u] = true;
//    }
//    for (int i = 0; i < n; ++i)
//        part[i] = NONE;
//
//    bool success = true;
//    int curPart = LEFT;
//    for (int i = 0; i < n && success; ++i)
//        if (part[i] == NONE) {
//            success &= makePartrition(i, curPart);
//            curPart = (curPart == LEFT) ? RIGHT : LEFT;
//        }
//
//    if (success) {
//        cout << parts[0].size() << endl;
//        for (int i = 0; i <= 1; ++i) {
//            for (int j = 0; j < n; ++j)
//                if (part[j] == i)
//                    cout << j + 1 << ' ';
//            cout << endl;
//        }
//    } else
//        cout << -1 << endl;
//    cin >> n;
//    return 0;
//}