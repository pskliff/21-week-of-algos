#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    unordered_map<char, bool> inclusions;

    string line1, line2;
    cin >> line1 >> line2;
    for ( char  i : line1) {
        inclusions[i] = true;
    }
    for ( char  i : line2) {
        inclusions[i] = false;
    }
    for ( char  i : line1) {
        if (inclusions[i])
            cout << i;
    }
    cout << endl;
    return 0;
}