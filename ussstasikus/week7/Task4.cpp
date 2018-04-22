//
// Created by Stas Don on 21/04/2018.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    long N;
    cin >> N;

    long five_power = 5;
    int count = 0;
    while(five_power <= N)
    {
        count += N/five_power;
        five_power *= 5;
    }
    cout << count;
}