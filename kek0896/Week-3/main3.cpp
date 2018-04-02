#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int len(pair<int, int> p1, pair<int, int> p2);

bool strait(int len1, int len2, int len3, int maxl);

pair<int, int> newPoint(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3,
                        int len1, int len2, int len3, int maxl);

int main()
{
    string lol;
    int n, x, y;

    ifstream fin;
    fin.open("input.txt");
    fin >> n;

    vector<pair<int, int>> kek;

    // reading points
    for (int i = 0; i < n; ++i)
    {
        fin >> x;
        fin >> y;
        kek.emplace_back(pair<int, int>(x, y));
        getline(fin, lol);
    }
    fin.close();

    int rectN = 0;
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {

                int len1 = len(kek[j], kek[k]), len2 = len(kek[i], kek[k]), len3 = len(kek[j], kek[i]);
                int maxl = max(max(len1, len2), len3);

                if (!strait(len1, len2, len3, maxl)) continue;

                if (find(kek.begin(), kek.end(), newPoint(kek[i], kek[j], kek[k], len1, len2, len3, maxl)) !=
                    kek.end())
                    rectN++;

            }
        }
    }

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << rectN / 4;
    fout.close();

    return 0;
}

bool strait(int len1, int len2, int len3, int maxl)
{
    return (maxl == len1 + len2 + len3 - maxl);
}

int len(pair<int, int> p1, pair<int, int> p2)
{
    return ((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

pair<int, int> newPoint(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, int len1, int len2, int len3, int maxl)
{
    pair<int, int> point;
    point.first = p1.first + p2.first + p3.first -
                  2 * ((maxl == len1) ? p1.first : (maxl == len2) ? p2.first : p3.first);
    point.second = p1.second + p2.second + p3.second -
                   2 * ((maxl == len1) ? p1.second : (maxl == len2) ? p2.second : p3.second);
    return point;
};