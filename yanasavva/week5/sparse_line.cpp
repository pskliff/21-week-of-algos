#include <iostream>
#include <fstream>

using namespace std;

void replace(string &s, int real_len, int len);
void create (string &s, int real_len);

int main() {
    string s;
    string n;
    fstream fin;
    fin.open("input.txt");
    getline(fin, n);

    getline(fin, s);

    create(s, atoi(n.c_str()));
    replace(s, atoi(n.c_str()), s.length());
    cout << s << endl;
    return 0;
}


void replace(string &s, int real_len, int len)
{
    int i = real_len - 1;
    int j = len - 1;
    while (i > 0)
    {
        if (s[i] == ' ')
            s[j--] = '0', s[j--] = '2', s[j--] = '%';
        else
            s[j--] = s[i];
        --i;
    }
}

void create (string &s, int real_len)
{
    while (s.length() < real_len)
        s += " ";

    int cnt = 0;
    for (int i = 0; i < s.length(); ++i)
        if (s[i] == ' ')
            ++cnt;
    s.resize(s.length() + cnt * 3 - cnt);
}