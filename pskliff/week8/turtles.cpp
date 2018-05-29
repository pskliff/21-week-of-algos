#include <iostream>
#include <vector>
#include <string>
#include <regex>


using namespace std;

typedef unsigned long long ull;

ull v, d, n;
ull max_time, max_dist;
vector<int> dst;
vector<int> times;


std::vector<std::string> split(const string& input, const string& regex)
{
    // passing -1 as the submatch index parameter performs splitting
    std::regex re(regex);
    std::sregex_token_iterator
            first{input.begin(), input.end(), re, -1},
            last;
    return {first, last};
}


int parseTime(const string& time)
{
    vector<string> buf = split(time, ":");
    string h = buf[0][0] == '0' ? string(1, buf[0][1]) : buf[0];
    string m = buf[1][0] == '0' ? string(1, buf[1][1]) : buf[1];
    int res = stoi(h) * 60 + stoi(m);
    return res;
}

ull binSearch()
{
    ull l = max_time, r = 1e16;
    while(l < r)
    {
        ull t = (l+r)/2;
        ull tn = t - d*n;
        ull dist = v * tn;
        if (dist < max_dist)
            l = t + 1;
        else
            r = t;
    }
    return min(l, r);
}


int main()
{
    cin >> v >> d >> n;
    for (int i = 0; i < n; ++i)
    {
        ull dist;
        string time;
        cin >> dist;
        dst.emplace_back(dist);
        cin >> time;
        ull tm = parseTime(time);
        times.emplace_back(tm);
    }

    max_time = times[n - 1];
    max_dist = dst[n - 1];

    ull tm = binSearch() + max_dist / v;
    ull h = tm / 60;
    ull m = tm % 60;
    string hh = (h/10) == 0 ? "0" + to_string(h) : to_string(h);
    string mm = (m/10) == 0 ? "0" + to_string(m) : to_string(m);
    cout << hh <<":" << mm <<endl;

    return 0;
}