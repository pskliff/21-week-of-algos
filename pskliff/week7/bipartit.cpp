#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> parts;

bool bfs(vector<vector<int>>& graph, int n, int start)
{
    queue<int> q;
    q.push(start);


    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        int part = parts[current];
        for (auto el : graph[current])
        {
            if (parts[el] == -1)
            {
                parts[el] = 1 - part;
                q.push(el);
            }
            else if (parts[el] == part)
                return false;
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    parts = vector<int>(n, -1);

    for (int i = 0; i < n; ++i)
    {
        if (parts[i] != -1)
            continue;

        parts[i] = 0;
        if (!bfs(graph, n, i))
            return false;
    }

    return true;
}

int main()
{

    return 0;
}

