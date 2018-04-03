#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

string fun(string& first, string& second){

    unsigned f = 0, s = 0;
    string res;
    while(true){

        while (first[f] < second[s]){
            res += first[f];
            f++;
            if(f >= first.length()) return res;
        }

        while(first[f] > second[s]){
            s++;
            if(s >= second.length())
                return  res + first.substr(f, first.length() - f);
        }

        while(first[f] == second[s]){
            f++;
            if(f >= first.length()) return res;
        }

    }

}

int main()
{
    string first, second;
    string res;

    ifstream fin;
    fin.open("input.txt");
    getline(fin, first);
    getline(fin, second);
    fin.close();

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    res = fun(first, second);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res;
    fout.close();

    return 0;
}