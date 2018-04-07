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

int get_cycle(node* ls)
{
    node* slow = ls->next, * fast = ls->next->next;
    while (slow != fast)
        slow = slow->next, fast = fast->next->next;
    int k = 0;
    slow = ls;
    while (slow != fast)
        slow = slow->next, fast = fast->next, ++k;
    return k;
}

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    int N, lp;

    fin >> N >> lp;

    int val;
    fin >> val;
    auto* ls = new node(val);
    node* current = ls, * loop = new node;

    for (int i = 1; i < N; ++i)
    {
        fin >> val;
        current->next = new node(val);
        current = current->next;
        if (lp == i)
            loop = current;
    }
    if (lp == 0)
        loop = ls;

    current->next = loop;

    int res = get_cycle(ls);

    fout << res;

    current = ls;
    for (int i = 0; i < N; ++i)
    {
        node* del = current;
        current = current->next;
        delete del;
    }

    fin.close();
    fout.close();

    return 0;
}