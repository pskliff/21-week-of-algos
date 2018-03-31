//
// Created by Stas Don on 22/03/2018.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<double> servers;

    double denominator = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        servers.emplace_back(a*b);
        denominator += a*b;
    }

    for (int i = 0; i < n; ++i)
        cout << servers[i]/denominator << endl;

}