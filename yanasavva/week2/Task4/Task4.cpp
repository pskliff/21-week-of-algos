#include <iostream>

std::pair<int, int> count_sums(int *arr,int n)
{
    int *sums = new int[n];
    std::pair<int,int> pair = std::make_pair(0,0);
    for (int i = 0; i < n; ++i)
    {
        int k = i;
        sums[i] = arr[i];
        for (int j = i + 1; j < n; ++j)
        {
            sums[j] = sums[j - 1] + arr[j];
            if (sums[j] == 0)
                k = j;
        }
        if (k - i > pair.second - pair.first)
            pair = std::make_pair(i, k);
    }
    return pair;

}

int main() {
    int n;
    std::cin >> n;
    int *arr = new int[n];
    for (int j = 0; j < n; ++j)
        std::cin >> arr[j];


    std::pair<int, int> pair = count_sums(arr, n);
    for (int i = pair.first; i <= pair.second ; ++i)
        std::cout << arr[i] << " ";

}