#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int rect[n][n];

    int sp = 0, ep = n;
    if(n % 2 == 1) {
        for(int k = n * n; k > 0; ++sp, --ep) {
            for(int i = sp; i < ep; ++i)
                rect[sp][i] = k--;
            for(int i = sp + 1; i < ep; ++i)
                rect[i][ep - 1] = k--;
            for(int i = ep - 2; i >= sp; --i)
                rect[ep - 1][i] = k--;
            for(int i = ep - 2; i >= sp + 1; --i)
                rect[i][sp] = k--;
        }
    } else {
        for(int k = n * n; k > 0; ++sp, --ep) {
            for(int i = sp; i < ep; ++i)
                rect[i][ep - 1] = k--;
            for(int i = ep - 2; i >= sp; --i)
                rect[ep - 1][i] = k--;
            for(int i = ep - 2; i >= sp; --i)
                rect[i][sp] = k--;
            for(int i = sp + 1; i < ep - 1; ++i)
                rect[sp][i] = k--;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%3d", rect[i][j]);
        std::cout << std::endl;
    }

        return 0;
}