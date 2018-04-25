#include <iostream>
#include <vector>


using namespace std;


int trailingZeroes(int n)
{
    int div = n;
    int sum = 0;
    do
    {
        div /= 5;
        sum += div;
    } while (div > 0);

    return sum;
}


int main()
{
    cout << trailingZeroes(100);
    return 0;
}

