//
// Created by Маргарита Мариампиллай on 22.04.2018.
//
#include <fstream>
#include <vector>

using namespace std;

bool mark_adj(vector<vector<int>> a, vector<int> &vert, vector<int> &pins, int pin){
    for (int &i : vert)
    {
        if (pins[i] == 0) {pins[i] = pin; mark_adj(a, a[i], pins, 3 - pin);}
        else if (pins[i] != pin) return false;

    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    vector<int> pins(graph.size(), 0);

    int pin = 2; // 3 - pin
    for(int i = 0; i < graph.size(); ++i){
        if(pins[i] == 0)
            pins[i] = pin;
        pin = 3 - pins[i];
        if(!mark_adj(graph, graph[i], pins, pin)) return false;
    }
    return true;
}

int main()
{

    ifstream fin("input.txt");
    int n;
    fin >> n;

    vector<vector<int>> a(n);
    vector<int> b(n);
    int elem;

    for (int i = 0; i < n; ++i) fin >> b[i];

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < b[i]; ++j)
        {
            fin >> elem;
            a[i].emplace_back(elem);
        }
    }

    fin.close();

    ofstream fout("output.txt");
    fout << isBipartite(a) << endl;
    fout.close();

    return 0;
}

// Test example

//5
//1 2 1 2 2
//3
//2 4
//1
//0 4
//1 3