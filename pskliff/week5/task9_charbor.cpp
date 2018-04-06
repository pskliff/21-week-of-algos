#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
const int ALFLEN = 26;

typedef unordered_map<int, unordered_set<int>> smType;

struct Node{
    Node* next[ALFLEN];
    bool leaf;
    Node()
    {
        for (int i = 0; i < ALFLEN; ++i)
            next[i] = nullptr;
    }

};

Node * root = new Node();

void make_path(string& s)
{
    Node* curr = root;
    for (int i = 0; i < s.length(); ++i)
    {
        int ind = s[i] - 'a';
        if (!curr->next[ind])
            curr->next[ind] = new Node();
        curr = curr->next[ind];
        if (i == s.length() - 1)
            curr->leaf = true;
    }
}

bool isInSteps(int i, int j, smType& steps){
    return steps.find(i) != steps.end() && steps[i].find(j) != steps[i].end();
}


int recursion(vector<string>& table, int n, int m, int i, int j, Node* came, smType & steps)
{
    Node * curr = came;
    int sum = 0;
    int ind = table[i][j] - 'a';
//    cout << table[i][j] << endl;
    if (!curr->next[ind])
        return 0;
    curr = curr->next[ind];
    steps[i].insert(j);

    sum += curr->leaf;
    if (i - 1 >= 0 && !isInSteps(i - 1, j, steps))
        sum += recursion(table, n, m, i - 1, j, curr, steps);
    if (j - 1 >= 0 && !isInSteps(i, j - 1, steps))
        sum += recursion(table, n, m, i, j - 1, curr, steps);
    if (i + 1 < n && !isInSteps(i + 1, j, steps))
        sum += recursion(table, n, m, i + 1, j, curr, steps);
    if (j + 1 < m && !isInSteps(i, j + 1, steps))
        sum += recursion(table, n, m, i, j + 1, curr, steps);
    return sum;
}

int findWords(vector<string>& table, vector<string>& dict)
{
    int n = table.size();
    int m = table[0].length();
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            unordered_map<int, unordered_set<int>> steps;
            //table[i][j]
            sum += recursion(table, n, m, i, j, root, steps);
        }
    }
    return sum;
}

bool isInTrie(string& s){
    Node * curr = root;
    for (int i = 0; i < s.length(); ++i)
    {
        int ind = s[i] - 'a';
        if (!curr->next[ind])
            return false;
        curr = curr->next[ind];
    }
    return curr->leaf;
}

int main()
{
//    string arr[] = {"fxie", "amlo", "aebx", "estu"};
//    vector<string> table(arr, arr + sizeof(arr) / sizeof(arr[0]));
//    string dic[] = {"fame", "sea", "loxu"};
//    vector<string> dict(dic, dic + sizeof(dic) / sizeof(dic[0]));
//    string arr[] = {"abm", "can", "aca"};
//    vector<string> table(arr, arr + sizeof(arr) / sizeof(arr[0]));
//    string dic[] = {"abaca"};
//    vector<string> dict(dic, dic + sizeof(dic) / sizeof(dic[0]));

    string arr[] = {"fxis", "amou", "aebx", "estu"};
    vector<string> table(arr, arr + sizeof(arr) / sizeof(arr[0]));
    string dic[] = {"fame", "sea", "famous"};
    vector<string> dict(dic, dic + sizeof(dic) / sizeof(dic[0]));

    for (auto el : dict)
    {
        make_path(el);
    }
//
//    for (auto el : dict)
//    {
//        cout << isInTrie(el) << endl;
//    }

    cout << findWords(table, dict);

    return 0;
}