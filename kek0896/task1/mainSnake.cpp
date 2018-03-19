#include <iostream>

int main()
{
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    if (n < 1)
    {
        std::cout << "Think bigger!\n ";
        return 0;
    }

    int arr[n][n];
    int start = n / 2 + n % 2 - 1;

    int r = start, c = start;
    arr[r][c] = 1;

    int stop2 = (n % 2 == 0) ? n - 1 : 0;

    int currentNumber = 2;
    int addR = 0, addC = 0;

    (n % 2 == 0) ? addR++ : addC--;

    int i = 0, j = 1;

    while (i < n * 2 - 1)
    {

        for (int k = 0; k < j; ++k)
        {
            r += addR;
            c += addC;
            arr[r][c] = currentNumber++;
            if((c == stop2) && (r == 0)) break;
        }

        if(i % 2 == 1) j++;
        i++;

        addC = (r > start && c <= start) - (r < start && c > start);
        addR = (r <= start && c < start) - (r > start && c > start);

    }

    for (int k = 0; k < n; ++k)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << arr[k][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    return 0;

}