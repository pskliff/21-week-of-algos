#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void sortingVectors(vector<pair<pair<int, int>, int>>& vect1, vector<pair<pair<int, int>, int>>& vect2);

int main()
{
    string lol;
    int n, x, y;

    ifstream fin;
    fin.open("input.txt");
    fin >> n;

    vector<pair<pair<int, int>, int>> vect1, vect2;
    vector<pair<int, int>> kek;

    // reading points
    for (int i = 0; i < n; ++i)
    {
        fin >> x;
        fin >> y;
        kek.emplace_back(pair<int, int>(x, y));
        vect2.emplace_back(pair<pair<int, int>, int>(kek[i], 0));
        getline(fin, lol);
    }
    fin.close();

    int rectN = 0;
    sortingVectors(vect1, vect2);

    for (int i = 0; i < n - 1; ++i)
    {
        int ind1 = i + 1;
        // if point 1 do not match with next
        while ((ind1 < n) && vect1[i].first.first == vect1[ind1++].first.first)
        {
            // if point 2 does not match
            int ind2 = vect1[ind1 - 1].second;
            if (ind2 + 1 == n) continue;

            while (vect2[ind2].first.second == vect2[ind2 + 1].first.second)
            {
                if (find(kek.begin(), kek.end(), pair<int, int>(vect2[ind2 + 1].first.first,
                                                                vect1[i].first.second)) != kek.end())
                    rectN++;
                ind2++;
                if (ind2 + 1 == n) break;
            }
        }
    }

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << rectN;
    fout.close();

    return 0;
}

// последний индекс - немного костыль, чтобы помнить место точки первого вектора во втором векторе
void sortingVectors(vector<pair<pair<int, int>, int>>& vect1, vector<pair<pair<int, int>, int>>& vect2){

    // sorting by y
    std::sort(vect2.begin(), vect2.end(), [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        if(a.first.second == b.first.second) return a.first.first < b.first.first;
        else return  a.first.second < b.first.second;
    });

    // memorizing indexes of points in second vector
    for(int i = 0; i < vect2.size(); i++){
        vect2[i].second = i;
    }

    vect1 = vect2;
    // sorting by x
    std::sort(vect1.begin(), vect1.end(), [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        if(a.first.first == b.first.first) return a.first.second < b.first.second;
        else return  a.first.first < b.first.first;
    });

}