#include <iostream>
#include <fstream>

using namespace std;

// stremnoe reshenie recursivnoe

bool validPalindrome(string s, int count)
{
    size_t p1 = 0, p2 = s.size() - 1;
    while (p1 < p2)
    {
        if (s[p1] != s[p2])
            return (++count < 2) && (validPalindrome(s.substr(p1, p2 - p1), count) ||
                    validPalindrome(s.substr(p1 + 1, p2 - p1), count));
        p1++; p2--;
    }
    return true;
}

bool validPalindrome(string s)
{
    return validPalindrome(s, 0);
}

int main()
{
    ifstream fin("input.txt");

    string str;
    fin >> str;
    fin.close();

    fstream fout("output.txt", ios::out);
    fout << (validPalindrome(str) ? "vse norm, mojno" : "nit, nizya");
    fout.close();

    return 0;
}