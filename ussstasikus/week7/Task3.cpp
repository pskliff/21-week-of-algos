//
// Created by Stas Don on 23/03/2018.
//

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int number_of_clicks = 0;

    unordered_set<string> words;

    for (int i = 0; i < n; ++i) {
        string word;
        cin>>word;
        if(words.find(word) == words.end())//если не было такого слова
        {
            words.insert(word);
            number_of_clicks += word.size();
        }
        else//если было такое слово
        {
            set<int> prefixes;//prefix_len
            for(auto it: words)
            {
                if(it != word)
                {
                    int prefix_len = 0;
                    while(prefix_len < it.size() && prefix_len < word.size() && it[prefix_len] == word[prefix_len])
                        ++prefix_len;

                    if(prefixes.find(prefix_len) == prefixes.end())
                        prefixes.insert(prefix_len);

                    if(prefix_len == word.size())
                        break;
                }
            }

            int max_prefix = *(--prefixes.end());
            if(max_prefix == word.size())
                number_of_clicks += word.size();
            else
                number_of_clicks += max_prefix + 1;
        }
    }
    cout << number_of_clicks;
}
