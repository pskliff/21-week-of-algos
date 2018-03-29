//
// Created by Stas Don on 26/03/2018.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


void addPrefixes(string word, unordered_map<string, int> &prefixes)
{
    string prefix = "";

    for(char symb: word)
    {
        prefix += symb;
        auto it = prefixes.find(prefix);
        if(it == prefixes.end())
            prefixes[prefix] = 1;
        else
            it->second += 1;
    }
}

int howManySymb(string word, unordered_map<string, int> &prefixes , unordered_set<string> &words)
{
    string pref = "";
    for(char symb: word)
    {
        pref += symb;
        if(prefixes[pref] == 1 &&words.find(pref) == words.end())
            return pref.size();
    }
    return pref.size();
}
int main()
{
    int n, symbols_to_write = 0;
    cin >> n;

    unordered_set<string> words;
    unordered_map<string, int> prefixes;


    for (int i = 0; i < n; ++i)
    {
        string word;
        cin >> word;

        if(words.find(word) == words.end())
        {
            words.insert(word);
            addPrefixes(word, prefixes);
            symbols_to_write +=  word.size();
        }
        else
            symbols_to_write += howManySymb(word, prefixes, words);
    }
    cout << symbols_to_write;



}