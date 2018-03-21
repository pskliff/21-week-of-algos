#include <iostream>

int main() {
    int n, s = 0;
    std::cin >> n;
    for(int i = 0, t; i < n - 1; ++i) {
        std::cin >> t;
        s += t;
    }
    std::cout << (1 + n) * n / 2 - s;
    return 0;
}