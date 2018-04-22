//
// Created by Маргарита Мариампиллай on 21.04.2018.
//

// updated variant 1
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n >= 5) { n /= 5; res += n; }
        return res;
    }
};