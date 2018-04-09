#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

bool can_draw(vector<pair<double, double>> &points);

void kaef_sort(vector<pair<double, double>> &points);

int main()
{
    string lol;
    int n;
    double x, y;

    ifstream fin;
    fin.open("input.txt");
    fin >> n;
    vector<pair<double, double>> kek;

    // reading points
    for (int i = 0; i < n; ++i)
    {
        fin >> x;
        fin >> y;
        kek.emplace_back(pair<double, double>(x, y));
        getline(fin, lol);
    }
    fin.close();

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << (can_draw(kek) ? "vse norm, mojno" : "nit, nizya");
    fout.close();

    return 0;
}


bool can_draw(vector<pair<double, double>> &p){

    if(p.size() < 2) return true;

    kaef_sort(p);

    int i = 0, j = p.size() - 1;
    double simsimX = (p[i].first + p[j].first);

    while(i <= j){
        if (p[i].first == p[j].first) return true;
        if ((p[i].second != p[j].second) ||
            simsimX != (p[i].first + p[j].first))
            return false;
        i++; j--;
    }

    return true;

}

void kaef_sort(vector<pair<double, double>> &points){

    std::sort(points.begin(), points.end(), [](const pair<double, double>& a, const pair<double, double>& b) {
        if(a.first == b.first) return a.second < b.second;
        else return  a.first < b.first;
    });

    std::sort(points.begin() + (points.size() / 2), points.end(), [](const pair<double, double>& a, const pair<double, double>& b) {
        if(a.first == b.first) return a.second > b.second;
        else return  a.first < b.first;
    });

}

//Tests

//4
//1 4
//4 4
//1 1
//4 1

//vse norm, mojno

//5
//1 4
//4 4
//1 1
//4 1
//2.5 10

// vse norm, mojno