#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
typedef pair<int,vector<int>> tVertice;


bool checkColoring(vector<tVertice> &graph, int i, int c)
{
    if(graph[i].first != -1)
        return graph[i].first == c;
    graph[i].first = c;
    bool res = true;
    for (int v : graph[i].second) {
        res &= checkColoring(graph, v, !c);
    }
//    if(graph[i].second.empty())

    return res;
}
int main()
{
    int n;
    ifstream fin;
    fin.open("input.txt");
    fin >> n;
    vector<tVertice> graph(n);
    for (int i = 0; i < n; ++i) {
        int m;
        fin >> m;
        graph[i] = make_pair(-1, vector<int>(m));
        for (int j = 0; j < m; ++j)
            fin >> graph[i].second[j];
    }

    cout << checkColoring(graph, 0, 1);

    return 0;
}

