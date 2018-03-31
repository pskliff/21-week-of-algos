#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void analyse_by_letters(string word, int &counter);

void find_prefs(const string &str);

unordered_set<string> voc;
unordered_map<string, bool> prefs;

int main() {

    int n;
    ifstream fin;
    fin.open("input.txt");

    fin >> n;

    int counter = 0;
    for (int i = 0; i < n; ++i) {
        string word;
        fin >> word;
        if (voc.find(word) == voc.end())
        {
            counter += word.length();
            find_prefs(word);
            voc.emplace(word);
        } else analyse_by_letters(word, counter);
    }
    fin.close();

    ofstream fout;
    fout.open("output.txt");
    fout << counter;

    fout.close();
}

void analyse_by_letters(string word, int &counter)
{
    string prefix = "";
    for (int i = 0; i < word.length(); ++i) {
        prefix += word[i];
        if(prefs[prefix])
        {
            counter += (i + 1);
            break;
        }
    }
}


void find_prefs(const string &str)
{
    string pref = "";
    for (int i = 0; i < str.length(); ++i) {
        pref += str[i];
        if(prefs.find(pref) == prefs.end())
            prefs[pref] = true;
        else prefs[pref] = false;
    }
}
