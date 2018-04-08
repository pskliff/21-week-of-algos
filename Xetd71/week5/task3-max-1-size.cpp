#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    bool isOneZero = true;
    int max = 0, prevVal = 0, valNow = arr[0];
    for(int i = 1; i < n; ++i) {
        if(arr[i] == 1) {
            ++valNow;
        } else {
            if(isOneZero && valNow + prevVal > max)
                max = valNow + prevVal;
            else if(valNow > max)
                max = valNow;
            prevVal = valNow;
            valNow = 0;
            isOneZero = arr[i - 1] == 1;
        }
    }
    if(isOneZero && valNow + prevVal > max)
        max = valNow + prevVal;
    else if(valNow > max)
        max = valNow;
    cout << max;
    return 0;
}