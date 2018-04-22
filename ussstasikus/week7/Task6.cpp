//
// Created by Stas Don on 21/04/2018.
//
#include <vector>
#include <iostream>
#include <queue>

using namespace std;


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int curr_part = 0;

        vector<int> part(n, -1);

        for (int i = 0; i < n; ++i)
        {
            if (part[i] == -1)
            {
                queue<int> q;
                q.push(i);

                part[i] = curr_part;

                while (!q.empty())
                {
                    int current = q.front();
                    q.pop();
                    for (int j = 0; j < graph[current].size(); ++j)
                    {
                        int to = graph[current][j];
                        if (current == to)
                            continue;
                        else if (part[to] != -1)
                        {
                            if (part[to] == part[current])
                                return false;

                            else
                                continue;
                        }
                        part[to] = 1 - part[current];
                        q.push(to);
                    }
                }

                curr_part = 1 - curr_part;
            }
        }
        return true;
    }

};