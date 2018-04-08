#include <fstream>

struct node
{
    node()
    {}

    explicit node(int v) : val(v), next(nullptr)
    {}

    int val;
    node* next;
};

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    int N;

    fin >> N;

    int val;
    fin >> val;
    auto* ls = new node(val);
    node* current = ls;
    for (int i = 0; i < N - 1; ++i)
    {
        fin >> val;
        current->next = new node(val);
        current = current->next;
    }

    node* prev = nullptr, * next = nullptr;
    current = ls;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    current = ls = prev;
    while (current != nullptr)
    {
        fout << current->val << " ";
        current = current->next;
    }

    current = ls;
    while (current != nullptr)
    {
        node* del = current;
        current = current->next;
        delete del;
    }

    fin.close();
    fout.close();

    return 0;
}