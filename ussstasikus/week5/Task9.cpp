//
// Created by Stas Don on 03/04/2018.
//

#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

bool good(int i, int j, int max_i, int max_j)
{
    return i >= 0 && j >= 0 && i < max_i && j < max_j;
}


bool isWordExist(string word , int i, int j, const vector<vector<char>> &letters, int pos = 0, char prev = 'a')
{
    if(!good(i, j, letters.size(), letters[0].size()) || letters[i][j] != word[pos])
        return false;

    if(letters[i][j] == word[pos] && pos == word.size() - 1)
        return true;

    bool r = isWordExist(word, i, j - 1, letters, pos + 1, 'r'),
            l = isWordExist(word, i, j + 1, letters, pos + 1, 'l'),
            u = isWordExist(word, i - 1, j, letters, pos + 1, 'u'),
            d = isWordExist(word, i + 1, j, letters, pos + 1, 'd');

    if(prev == 'l')
        r = false;
    else if(prev == 'r')
        l = false;
    else if(prev == 'u')
        d = false;
    else if(prev == 'd')
        u = false;

    return r || l || u || d;

}


int maxAmountOfWords(const vector<string> words, const vector<vector<char>> letters)
{
    unordered_map<char, vector<pair<int, int>>> dict;
    for (int i = 0; i < letters.size(); ++i) {
        for (int j = 0; j < letters[i].size(); ++j) {
            if(dict.find(letters[i][j]) == dict.end())
                dict[letters[i][j]] = {pair<int, int>(i, j)};
            else
                dict[letters[i][j]].emplace_back(i, j);
        }
    }

    int count = 0;
    for(string word: words)
    {
        if(dict.find(word[0]) != dict.end())
        {
            for(auto ind: dict[word[0]])
            {
                if(isWordExist(word, ind.first, ind.second, letters))
                {
                    ++count;
                    break;
                }

            }
        }
    }

    return count;
}

int main()
{
    int n_words, n_rows, n_col;
    cin >> n_words;

    vector<string> words(n_words);

    for (int i = 0; i < n_words; ++i) {
        cin >> words[i];
    }

    cin  >> n_rows >> n_col;
    vector<vector<char>> letters(n_rows, vector<char>(n_col));


    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_col; ++j) {
            cin >> letters[i][j];
        }
    }

    cout << maxAmountOfWords(words, letters);
}

//5
//a aaa aba acb ba
//3 3
//a a b
//c a b
//b f f