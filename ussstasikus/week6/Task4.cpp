//
// Created by Stas Don on 11/04/2018.
//

class Solution {
public:
    bool isPalindrome(string s) {
        size_t start = 0, end = s.size() - 1;
        while(start < end)
        {
            while(!isalnum(s[start]))
                ++start;
            while(!isalnum(s[end]))
                --end;
            if(start < end && tolower(s[start]) != tolower(s[end]))
                return false;
            ++start;
            --end;
        }
        return true;
    }
};