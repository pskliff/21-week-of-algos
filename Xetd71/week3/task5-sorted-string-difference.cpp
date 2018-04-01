#include <iostream>
#include <string>
using namespace std;

/*23479AALgrs
1113468AFLafffh*/

int main()
{
    string s1, s2, res;
    cin >> s1 >> s2;

    int i = 0, j = 0, n1 = s1.length(), n2 = s2.length();
    for(; i < n1; ++i) {
        for(; s1[i] > s2[j] && j < n2;){
            ++j;
        }
        if(s1[i] != s2[j])
            res += s1[i];
    }

    cout << (res.empty() ? "-1" : res);
    return 0;
}