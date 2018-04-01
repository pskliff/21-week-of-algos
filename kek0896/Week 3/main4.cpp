#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main()
{
    string first, second;
    string res;

    ifstream fin;
    fin.open("input.txt");
    getline(fin, first);
    getline(fin, second);
    fin.close();

    unordered_map<char, bool> exclude;

    for(char letter: second)
        exclude[letter] = true;
    for(char letter: first)
        if(!exclude[letter]) res += letter;

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res;
    fout.close();

    return 0;
}

