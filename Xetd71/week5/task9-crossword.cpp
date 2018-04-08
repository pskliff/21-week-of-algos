#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;

struct Node {
    int n;
    Node* words[26];
    Node(int n) : n(n) {
        for(int i = 0; i < 26; ++i)
            words[i] = nullptr;
    }
    ~Node() {
        for(int i = 0; i < 26; ++i)
            delete words[i];
    }
};

Node* createDict(const vector<string>& words) {
    Node* root = new Node(0);
    for(const string& s : words) {
        Node* cur = root;
        for(int i = 0; i < s.length(); ++i) {
            int j = s[i] - 'a';
            if(cur->words[j] == nullptr)
                cur->words[j] = new Node(0);
            cur = cur->words[j];
            cur->n += 1;
        }
    }
    return root;
}

void findWords(unordered_set<string>& ss, char** letters, int n, Node* cur, string s, unordered_map<int, unordered_set<int>> steps, int i, int j) {
    if(cur->words[letters[i][j] - 'a'] == nullptr)
        return;
    steps[i].insert(j);
    cur = cur->words[letters[i][j] - 'a'];
    s += letters[i][j];
    if(i > 0 && steps[i - 1].find(j) == steps[i - 1].end())
        findWords(ss, letters, n, cur, s, steps, i - 1, j);
    if(i < n - 1 && steps[i + 1].find(j) == steps[i + 1].end())
        findWords(ss, letters, n, cur, s, steps, i + 1, j);
    if(j > 0 && steps[i].find(j - 1) == steps[i].end())
        findWords(ss, letters, n, cur, s, steps, i, j - 1);
    if(j < n - 1 && steps[i].find(j + 1) == steps[i].end())
        findWords(ss, letters, n, cur, s, steps, i, j + 1);
    ss.insert(s);
}

vector<string> findWords(char** letters, int n, const vector<string>& words) {
    Node* root = createDict(words);
    unordered_set<string> ss;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            string s;
            unordered_map<int, unordered_set<int>> steps;
            findWords(ss, letters, n, root, s, steps, i, j);
        }
    }
    vector<string> inter;
    unordered_set<string> sWords(words.begin(), words.end());
    set_intersection(sWords.begin(), sWords.end(), ss.begin(), ss.end(), back_inserter(inter));
    delete root;
    return inter;
}


int main()
{
    int n;
    cin >> n;
    char **letters;
    letters = new char*[n];
    for(int i = 0; i < n; ++i)
        letters[i] = new char[n];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> letters[i][j];

    int k;
    cin >> k;
    string s;
    vector<string> words;
    for(int i = 0; i < k; ++i) {
        cin >> s;
        words.emplace_back(s);
    }

    for(const string& sa : findWords(letters, n, words))
        cout << sa << ' ';

    for(int i = 0; i < n; ++i)
        delete[] letters[i];
    delete[] letters;
    return 0;
}

/*
4
f x i e
a m l o
e e b x
a s t u
3
fame
sae
loxu

2
a b
c a
3
abac
abaca
abab
*/