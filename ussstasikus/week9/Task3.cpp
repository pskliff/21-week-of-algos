//
// Created by Stas Don on 01/06/2018.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element
{
    int id;
    int value;
    Element(int id, int value):id(id), value(value)
    {}
};

bool elComp(const Element& l, const Element& r)
{
    return l.value < r.value;
}


int formElphsAndOLENs(vector<Element> &elphs, vector<Element> &OLENs, string &res, int amount)
{
    size_t n = elphs.size();
    int cnt = 0;
    int olen_id = 0;
    while(olen_id < OLENs.size())
    {
        if(elphs[cnt].value < OLENs[olen_id].value && elphs[n - amount + cnt].value > OLENs[olen_id].value) {
            res += to_string(OLENs[olen_id].id) + " " + to_string(elphs[cnt].id) + " " + to_string(elphs[n - amount + cnt].id) + '\n';
            ++cnt;
        }

        ++olen_id;
    }

    if(cnt == 0)
        return -1;
    else
        return cnt;
}

int binSearch(vector<Element> &elphs, vector<Element> &OLENs, string &last_max)
{
//    int l = 0, r = min(OLENs.size(), elphs.size()/2);
//
//    int last_max_cnt = 0;
//    while(l < r - 1)
//    {
//        int m = l + (r - l)/2;
//        string res;
//        int cnt = formElphsAndOLENs(elphs, OLENs, res, m);
//        if(cnt != -1) {
//            l = m;
//            last_max = res;
//            last_max_cnt = cnt;
//        }
//        else
//            r = m - 1;
//    }
//    return last_max_cnt;

    int l = 0, r = min(OLENs.size(), elphs.size()/2);

    int last_max_cnt = 0;
    while(l < r - 1)
    {
        int m = l + (r - l)/2;
        string res;
        int cnt = formElphsAndOLENs(elphs, OLENs, res, m);
        if(cnt != -1) {
            l = m;
            last_max = res;
            last_max_cnt = cnt;
        }
        else
            r = m - 1;
    }

    string prob_res;
    int prob_cnt = formElphsAndOLENs(elphs, OLENs, prob_res, r);
    if(prob_cnt != -1)
    {
        last_max = prob_res;
        return prob_cnt;
    }
    return last_max_cnt;
}

int main()
{
    ifstream fin("input.txt");
    int n, m;
    fin >> m >> n;
    vector<Element> elphs, OLENs;
    for (int i = 0; i < m; ++i)
    {
        int val;
        fin >> val;
        OLENs.emplace_back(i + 1, val);
    }

    for (int i = 0; i < n; ++i)
    {
        int val;
        fin >> val;
        elphs.emplace_back(i + 1, val);
    }

    ofstream fout("output.txt");

    sort(elphs.begin(), elphs.end(), elComp);
    sort(OLENs.begin(), OLENs.end(), elComp);

    string res;
    fout << binSearch(elphs, OLENs, res) << '\n' << res;
}