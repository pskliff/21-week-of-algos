#include <iostream>

using namespace std;

int main()
{
    const int n = 8;
    int arr[n] = {1, 0, 0, 0, 0, 1, 0, 1};
    int buf = 0;
    if (arr[0] == 0)
    {
        arr[0] = 1;
        buf = 1;
    }
    else
        arr[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] == 0)
        {
            ++buf;
            arr[i] = arr[i - 1];
        }
        else
            arr[i] = arr[i - 1] + buf;
    }

    cout << arr[n - 1];
    return 0;
}
