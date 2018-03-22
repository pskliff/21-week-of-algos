//
// Created by Stas Don on 20/03/2018.
//

#include <iostream>

int main() {

    int zeros_amount = 0, pairs = 0;
    std::string line;
    std::cin >> line;
    int n = line.size();
    for (int i = 0; i < n; ++i) {
        int digit = line[i] - '0';
        if(digit == 0)
            ++zeros_amount;
        else
            pairs += zeros_amount;
    }
    std::cout << pairs;
}