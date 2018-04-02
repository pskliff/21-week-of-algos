#include <iostream>
using namespace std;

int main() {

    string line;
    cin >> line;
    int cnt = 0;

    int mult = 0;
    for (int i = line.length() - 1; i >= 0; --i) {
       if (line[i] - '0' == 1)
           ++mult;
       else cnt += mult;
    }
    cout << cnt << endl;
    return 0;
}