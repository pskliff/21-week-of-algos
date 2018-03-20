#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int arr[n][n];

    int turn = n % 2 == 0 ? 1 : 0, i = 0, j;
    int count = 0;
    int even = n % 2 == 0;
    while(turn <= 2 * n - !even)
    {
        j = i;

        if (j == n - i - 1)
            arr[i][j] = 1;
        while (j < n - i - 1)
        {
            if (turn % 4 == 0)
            {
                arr[i][j] = n*n - count++;
            } else if (turn % 4 == 1)
            {
                arr[j][n - i - 1] = n*n - count++;
            } else if (turn % 4 == 2)
            {
                arr[n - i - 1][n - j - 1] = n*n - count++;
            } else if (turn % 4 == 3)
            {
                arr[n - j - 1][i] = n*n - count++;
            }

            ++j;
        }
        ++turn;
        if (turn % 4 == even)
            ++i;
    }
    for (int k = 0; k < n; ++k)
    {
        for (int l = 0; l < n; ++l)
            std::cout << arr[k][l] << " ";
        std::cout << std::endl;
    }
}