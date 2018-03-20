#include <map>
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::map<int, int> sums;
    int len, j;
    len = j = -1;
    for(int i = 0, s = 0, t; i < n; ++i) {
        std::cin >> t;
        s += t;
        if(sums.count(s) > 0) {
            if(i - sums[s] > len) {
                j = sums[s];
                len = i - j;
            }
        } else {
            sums[s] = i;
        }
    }
    std::cout << j << " " << len;
    return 0;
}