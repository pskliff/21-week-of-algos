#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    int fives = 0;

    unsigned long long pow = 1;
    int i = 0;
    while( pow * 5 <= n)
        pow *= 5, ++i;
    for (; pow > 0; pow /= 5, --i)
    {
        int div5 = n / pow ;
        cnt += (div5 - fives) * i;
        fives = div5;
    }
    cout << cnt << endl;
    return 0;
}

