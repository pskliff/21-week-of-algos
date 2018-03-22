#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    for (int j = 0; j < n - 1; ++j)
        std::cin >> arr[j];
    int absent = 0;
    for (int i = 0; i < n - 1; ++i)
        absent += (i + 1 - arr[i]);
    std::cout << "The Absent element is: " << absent + n;

}