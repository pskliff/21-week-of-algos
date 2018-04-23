#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    ifstream fin;
    fin.open("input.txt");
    long n,k;
    fin >> n >> k;
    vector<int> a1(n);
    vector<int> a2(k);

    for (long i = 0; i < n; ++i) {
        fin >> a1[i];
    }
    for (long i = 0; i < k; ++i) {
        fin >> a2[i];
    }

    for (long i = 0; i < k; ++i) {
        int left = 0, right = n - 1;
        int ind = 0;
        while (right - left > 1)
        {
            ind = (left + right) / 2;
            if (a1[ind] > a2[i])
                right = ind;
            else left = ind;
        }
        int target = abs(a2[i] - a1[left]) > abs(a2[i] - a1[right]) ? a1[right] : a1[left];
        cout << target << endl;
    }
    return 0;
}