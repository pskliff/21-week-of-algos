#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;


int *group;
bool **adj;
vector<int> groups[2];

bool assign_groups(int n, int vertice)
{
    queue<int> assigned;
    assigned.push(vertice);
    while(!assigned.empty())
    {
        int cur_vertice = assigned.front();
        assigned.pop();
        for (int i = 0; i < n; ++i)
        {
            if( i == cur_vertice || adj[i][cur_vertice])
                continue;
            if(group[i] == group[cur_vertice])
                return false;
            if (group[i] == -1)
            {
                group[i] = !group[cur_vertice];
                groups[group[i]].push_back(i);
                assigned.push(i);
            }
        }
    }
    return true;
}

int main(){

    int n,m;
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");

    fin >> n >> m;
    adj = new bool* [n];
    group = new int[n];
    for (int j = 0; j < n; ++j)
    {
        adj[j] = new bool[n];
        group[j] = -1;
    }

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        fin >> u >> v;
        adj[u - 1][v - 1] = adj[v - 1][u - 1] = true;
    }

    fin.close();
    fout.open("output.txt");
    int cur_group = 0;
    for (int i = 0; i < n; ++i)
    {
        if (group[i] == -1)
        {
            group[i] = cur_group;
            groups[cur_group].push_back(i);
            if (!assign_groups(n, i))
            {
                fout << -1;
                delete[] group;
                for (int l = 0; l < n; ++l)
                    delete[] adj[l];
                return 0;
            } else cur_group = !cur_group;
        }
    }
    fout << groups[0].size() << endl;

    for (int k : groups[0]) {
        fout << k + 1<< " ";
    }

    fout << endl;

    for (int k : groups[1]) {
        fout << k + 1 << " ";
    }

    delete[] group;
    for (int l = 0; l < n; ++l)
        delete[] adj[l];


    return 0;
}