#include <iostream>
using namespace std;

int main() {

    string line1, line2;
    cin >> line1 >> line2;

    int k = 0, i = 0;
    for (; i < line1.length();) {
        if (k >= line2.length())
            cout << line1[i++];
        else
        {
            if (line1[i] > line2[k])
                ++k;
            else if (line1[i] < line2[k])
                cout << line1[i++];
            else
                ++i, ++k;
        }
    }
    return 0;
}
