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
        long left = 0, right = n - 1;
        long ind = 0;
        long first = 0, second = 0;
        bool found = false;
        while (right - left > 1)
        {
            ind = (left + right) / 2;
            if (a1[ind] > a2[i])
                right = ind;
            else if (a1[ind] < a2[i])
                     left = ind;
            else
                {
                    first = second = ind;
                    while(first > 0 && a1[first - 1] == a2[i])
                        --first;
                    while (second < n - 1 && a1[second + 1] == a2[i])
                        ++second;
                    found = true;
                    cout << first + 1 << " " << second + 1 << endl;
                    break;

                }
        }

        if (!found)
        {
            if (a1[right] == a2[i])
                cout << right + 1 << " " << right + 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}