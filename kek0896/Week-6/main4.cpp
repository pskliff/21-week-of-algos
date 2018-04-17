#include <iostream>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

bool isPalindrome(string s) {
    int p1 = 0, p2 = s.size() - 1;
    while(p1 < p2){
        while(!isalnum(s[p1]) && p1 < p2) ++p1;
        while(!isalnum(s[p2]) && p2 > p1) --p2;
        if(tolower(s[p1++]) != tolower(s[p2--])) return false;
    }
    return true;
}

int main()
{
    ifstream fin("input.txt");

    string str;
    fin >> str;
    fin.close();

    fstream fout("output.txt", ios::out);
    fout << (isPalindrome(str) ? "true" : "false");
    fout.close();

    return 0;
}
