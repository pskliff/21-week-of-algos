#include <iostream>
#include <set>
using namespace std;

struct Node {
    int n;
    Node* words[26];
    Node(int n) : n(n) {
        for(int i = 0; i < 26; ++i) {
            words[i] = nullptr;
        }
    }
};

std::set<string> words;
Node* root = new Node(0);

void insert(const string& s)
{
    Node* cur = root;
    for(int i = 0, j; i < s.length(); ++i) {
        j = s[i] - 'a';
        if(cur->words[j] == nullptr)
            cur->words[j] = new Node(0);
        cur = cur->words[j];
        cur->n += 1;
    }
    words.insert(s);
}

int count(const string& s)
{
    Node* cur = root;
    for(int i = 0; i < s.length(); ++i) {
        cur = cur->words[s[i] - 'a'];
        if(cur->n == 1)
            return i + 1;
    }
    return s.length();
}


int main()
{
    int n, sum = 0;
    cin >> n;
    string s;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        if(words.count(s)) {
            sum += count(s);
        } else {
            insert(s);
            sum += s.length();
        }
    }
    cout << sum;
    delete root;
    return 0;
}