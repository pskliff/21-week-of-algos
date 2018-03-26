//
// Created by Stas Don on 24/03/2018.
//

//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    int curr_part = 0;
    bool is_two_parts = true;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n));
    vector<int> part(n, -1);
    vector<int> parts[2];

    for (int i = 0; i < m; ++i)
    {

        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        graph[v1][v2] = true;
        graph[v2][v1] = true;
    }

    for (int i = 0; i < n; ++i)
    {
        if (part[i] == -1)
        {
            queue<int> queue1;
            parts[curr_part].push_back(i);
            queue1.push(i);

            part[i] = curr_part;

            while (!queue1.empty())
            {
                int current = queue1.front();
                queue1.pop();
                for (int j = 0; j < n; ++j)
                {
                    if (graph[current][j] || current == j)
                        continue;
                    else if (part[j] != -1)
                    {
                        if (part[j] == part[current])
                            is_two_parts = false;
                        else
                            continue;
                    }
                    part[j] = 1 - part[current];  //обновляем сведения о доле для текущей вершины
                    parts[part[j]].push_back(j); //добавляем вершину в долю
                    queue1.push(j);
                }
            }

            curr_part = 1 - curr_part;
        }
    }

    if (is_two_parts)
    {
        cout << parts[0].size() << endl;
        for(int v: parts[0])
            cout << v + 1 << " ";
        cout << endl;

        for(int v: parts[1])
            cout << v + 1 << " ";
    }
    else
        cout << "-1";

    return 0;
}