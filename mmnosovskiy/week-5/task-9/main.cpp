#include <fstream>
#include <unordered_map>

const int ALPHABET_SIZE = 26;
const int MMAX = 100;
int N, M;
char a[MMAX][MMAX];

struct TrieNode
{
    TrieNode* children[ALPHABET_SIZE];

    bool isEndOfWord;
    bool wasFound;
    bool isPrefix;
};

TrieNode* getNode()
{
    auto* node = new TrieNode;
    node->isEndOfWord = false;
    node->wasFound = false;
    node->isPrefix = false;
    for (auto &i : node->children)
        i = nullptr;
    return node;
}

void insert(TrieNode* root, const std::string &key)
{
    TrieNode* current = root;
    for (char i : key)
    {
        int index = i - 'a';
        if (!current->children[index])
            current->children[index] = getNode();
        current = current->children[index];
        current->isPrefix = true;
    }
    current->isEndOfWord = true;
}

int countWords(TrieNode* node, int i, int j, std::unordered_map<int, std::unordered_map<int, int>> history)
{
    int count = 0;
    if (!node->isPrefix)
        return 0;
    if (node->isEndOfWord && !node->wasFound)
        ++count;
    if (i + 1 < M && (history.find(i + 1) == history.end() || history[i + 1].find(j) == history[i + 1].end()) &&
        node->children[a[i + 1][j] - 'a'] != nullptr)
        history[i + 1][j] = j, count += countWords(node->children[a[i + 1][j] - 'a'], i + 1, j, history);
    if (i - 1 >= 0 && (history.find(i - 1) == history.end() || history[i - 1].find(j) == history[i - 1].end()) &&
        node->children[a[i - 1][j] - 'a'] != nullptr)
        history[i - 1][j] = j, count += countWords(node->children[a[i - 1][j] - 'a'], i - 1, j, history);
    if (j + 1 < M && (history.find(i) == history.end() || history[i].find(j + 1) == history[i].end()) &&
        node->children[a[i][j + 1] - 'a'] != nullptr)
        history[i][j + 1] = j + 1, count += countWords(node->children[a[i][j + 1] - 'a'], i, j + 1, history);
    if (j - 1 >= 0 && (history.find(i) == history.end() || history[i].find(j - 1) == history[i].end()) &&
        node->children[a[i][j - 1] - 'a'] != nullptr)
        history[i][j - 1] = j - 1, count += countWords(node->children[a[i][j - 1] - 'a'], i, j - 1, history);
    return count;
}

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    fin >> N >> M;

    TrieNode* root = getNode();

    for (int i = 0; i < N; ++i)
    {
        std::string word;
        fin >> word;
        insert(root, word);
    }
    for (int i = 0; i < M * M; ++i)
    {
        char c;
        fin >> c;
        a[i / M][i % M] = c;
    }

    int count = 0;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < M; ++j)
        {
            if (!root->children[a[i][j] - 'a'])
                continue;
            std::unordered_map<int, std::unordered_map<int, int>> history;
            count += countWords(root->children[a[i][j] - 'a'], i, j, history);
        }

    fout << count;

    fin.close();
    fout.close();

    return 0;
}