#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int max = 0, cnt = 0, len = 0;
    for (int i = 0; i < n; ++i)
    {
        if(arr[i] == 1)
        {
            ++cnt, ++len;
            if (cnt > max)
                max = cnt;
        }
        else
        {
            if (len > cnt)
                cnt = 1, len = 1;
            if (i + 1 < n && arr[i + 1] == 0)
                ++i, cnt = 0, len = 0;

            ++len;
        }
    }

    cout << max << endl;
    return 0;
}
