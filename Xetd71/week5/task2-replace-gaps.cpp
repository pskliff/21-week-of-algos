#include <iostream>

using namespace std;

void replaceGaps(string& s, int expandedLen, int len)
{
    for(int i = len - 1, j = expandedLen - 1; i >= 0; --i, --j) {
        if(s[i] == '_') {
            s[j--] = '0';
            s[j--] = '2';
            s[j] = '%';
        } else {
            s[j] = s[i];
        }
    }
}

int main()
{
    string s;
    int expandedLen, len;
    cin >> s >> expandedLen >> len;
    replaceGaps(s, expandedLen, len);
    cout << s;
    return 0;
}


/*
a_d_bt_w________
17 9
*/