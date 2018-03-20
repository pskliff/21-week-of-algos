#include <iostream>

void setRect(int** rect, int n)
{
    if(n <= 0)
        return;

    if(n == 1) {
        rect[0][0] = 1;
        return;
    } else if(n == 2) {
        rect[0][0] = 1;
        rect[1][0] = 2;
        rect[1][1] = 3;
        rect[0][1] = 4;
        return;
    }

    int k = n * n;
    if(n % 2 == 1) {
        for(int i = 0; i < n; ++i)
            rect[0][i] = k--;
        for(int i = 1; i < n; ++i)
            rect[i][n - 1] = k--;
        for(int i = n - 1; i >= 0; --i)
            rect[n - 1][i] = k--;
        for(int i = n - 1; i >= 1; --i)
            rect[i][0] = k--;
        setRect(rect + 1, n - 2);
    } else {
        for(int i = 0; i < n; ++i)
            rect[i][n - 1] = k--;
        for(int i = n - 2; i >= 0; --i)
            rect[n - 1][i] = k--;
        for(int i = n - 2; i >= 0; --i)
            rect[i][0] = k--;
        for(int i = 1; i < n - 1; ++i)
            rect[0][i] = k--;
        setRect(rect + 1, n - 2);
    }
}

void printRect(int** rect, int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%3d", rect[i][j]);
        std::cout << std::endl;
    }

}

int main()
{
    int n;
    std::cin >> n;
    int** rect = new int*[n];
    for(int i = 0; i < n; ++i)
        rect[i] = new int[n];
    setRect(rect, n);
    printRect(rect, n);
    return 0;
}