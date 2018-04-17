#include <iostream>
#include <fstream>

using namespace std;

bool contains(string t, string p)
{

    long q[256] = {0}; // кол-во каждого символа (quantity)
    long q_c[256];     // текущее кол-во символов (current quantity)

    for (char i : p)
        q[i]++;
    memcpy(q_c, q, sizeof(q_c));

    long count = 0;
    for (char ch : t)
    {
        if (q_c[ch] == 0)
        {
            count = 0; memcpy(q_c, q, sizeof(q_c));
        } else { q_c[ch]--; count++; }
        if(count == p.length()) return true;  // кстати, если p - пустая - верну true, а если t - false
    }
    return false;

}

int main(int argc, char **argv)
{
    int n;
    ifstream fin("input.txt");
    fstream fout("output.txt", ios::out);

    string t, p;
    getline(fin, t);
    getline(fin, p);
    fin.close();

    fout << (contains(t, p) ? "contains" : "doesn't contain") << endl;
    fout.close();
}

// Tests
//lalala kjila
// ajk

// contains
