#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
bool check_letter(char letter);

int main()
{
    string s;
    cin >> s;
    int i = 0, j = s.length() - 1;
    string res = "polindrom";
    while (i != j)
    {
        if (!check_letter(s[i])) {
            ++i;
            continue;
        }
        if (!check_letter(s[j])) {
            --j;
            continue;
        }
        if (s[i] != s[j])
        {
            res = "nonpolindrom";
            break;
        }
        ++i, --j;

    }
    cout << res;

    return 0;
}


bool check_letter(char letter)
{
    return letter >= 'A' && letter <= 'z' ||
            letter >= 'А' && letter <= 'я';
}