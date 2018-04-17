#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool stringTemplate(const string& p, const string& t) {
    unordered_map<char, int> m;
    for(int i = 0; i < p.length(); ++i) {
        if(m.count(p[i]))
            --m[p[i]];
        else
            m[p[i]] = -1;
        if(m.count(t[i]))
            ++m[t[i]];
        else
            m[t[i]] = 1;
    }
    int s = 0;
    for(auto& el : m)
        if(el.second != 0)
            ++s;
    if(s == 0)
        return true;
    int n = p.length();
    for(int i = n; i < t.length(); ++i) {
        if(t[i - n] == t[i])
            continue;
        if(m.count(t[i - n])) {
            if(m[t[i - n]] == 1)
                --s;
            else if(m[t[i - n]] == 0)
                ++s;
            --m[t[i - n]];
        }
        if(m.count(t[i])) {
            if(m[t[i]] == -1)
                --s;
            else if(m[t[i]] == 0)
                ++s;
            ++m[t[i]];
        }
        if(s == 0)
            return true;
    }
    return false;
}

int main()
{
    string t, p;
    cin >> t >> p;
    cout << stringTemplate(p, t);
    return 0;
}
