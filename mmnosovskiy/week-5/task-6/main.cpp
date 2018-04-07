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


int get_dot(node* a, int len_a, node* b, int len_b)
{
    node* cur_a = a, * cur_b = b;
    int k = 0;
    if (len_a > len_b)
        for (int i = 0; i < len_a - len_b; ++i)
            cur_a = cur_a->next, ++k;
    else
        for (int j = 0; j < len_b - len_a; ++j)
            cur_b = cur_b->next;
    while (cur_a != cur_b)
        cur_a = cur_a->next, cur_b = cur_b->next, ++k;
    return k;
}

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    int len_a, len_b, c;

    fin >> len_a >> len_b >> c;

    int val;
    fin >> val;
    auto* a = new node(val);
    node* current = a, * connection = new node;

    for (int i = 1; i < len_a; ++i)
    {
        fin >> val;
        current->next = new node(val);
        current = current->next;
        if (c == i)
            connection = current;
    }
    if (c == 0)
        connection = a;

    fin >> val;
    auto* b = new node(val);
    current = b;

    for (int i = 1; i < len_b; ++i)
    {
        fin >> val;
        current->next = new node(val);
        current = current->next;
    }
    current->next = connection;

    int res = get_dot(a, len_a, b, len_b + len_a - c);
    fout << res;

    node* cur_a = a, * cur_b = b;
    for (int i = 0; i < len_b; ++i)
    {
        node* del = cur_b;
        cur_b = del->next;
        del->next = nullptr;
        delete del;
    }
    while (cur_a != nullptr)
    {
        node* del = cur_a;
        cur_a = del->next;
        del->next = nullptr;
        delete del;
    }

    fin.close();
    fout.close();

    return 0;
}