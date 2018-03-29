#include <iostream>
#include <fstream>

using namespace std;
int main() {

    ifstream fin;
    int n;
    fin.open("input.txt");
    int sum = 0;

    fin >> n;
    int servers[n];
    for (int i = 0; i < n; ++i) {
        int bi, ai;
        fin >> ai >> bi;
        servers[i] = ai * bi;
        sum += bi * ai;
    }

    fin.close();

    cout.precision(12);
    cout << fixed;
    for (int j = 0; j < n; ++j)
    {
        cout << servers[j] * 1.0 / sum << endl;
    }

    return 0;
}