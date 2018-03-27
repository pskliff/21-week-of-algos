#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

typedef pair<long long, int> valType;

struct node
{
    node* l, * r;
    long long dev, man, sum_dev, sum_man;
    int size, id, key;

    node(long long dev, long long man, int id)
    {
        this->dev = dev;
        this->man = man;
        this->sum_dev = dev;
        this->sum_man = man;
        this->size = 1;
        this->id = id;
        this->key = rand();
        this->l = this->r = nullptr;
    }

    valType value()
    {
        return make_pair(dev - man, id);
    }
};

typedef node* treap;

long long getDevSum(treap t)
{
    if (t == nullptr)
        return 0;
    else
        return t->sum_dev;
}

long long getManSum(treap t)
{
    if (t == nullptr)
        return 0;
    else
        return t->sum_man;
}

int getSize(treap t)
{
    if (t == nullptr)
        return 0;
    else
        return t->size;
}

void update(treap t)
{
    if (t == nullptr)
        return;
    t->sum_dev = getDevSum(t->l) + getDevSum(t->r) + t->dev;
    t->sum_man = getManSum(t->l) + getManSum(t->r) + t->man;
    t->size = getSize(t->l) + getSize(t->r) + 1;
}

void split(treap root, treap &l, treap &r, valType val)
{
    if (root == nullptr)
    {
        l = r = nullptr;
        return;
    }
    if (root->value() <= val)
    {
        l = root;
        split(l->r, l->r, r, val);
    }
    else
    {
        r = root;
        split(r->l, l, r->l, val);
    }
    update(root);
}

void splitBySize(treap root, treap &l, treap &r, int size)
{
    if (root == nullptr)
    {
        l = r = nullptr;
        return;
    }
    if (getSize(root->l) + 1 <= size)
    {
        l = root;
        splitBySize(l->r, l->r, r, size - getSize(root->l) - 1);
    }
    else
    {
        r = root;
        splitBySize(r->l, l, r->l, size);
    }
    update(root);
}

treap merge(treap l, treap r)
{
    if (l == nullptr || r == nullptr)
    {
        if (l != nullptr)
            return l;
        else
            return r;
    }
    treap root;
    if (l->key > r->key)
    {
        root = l;
        l->r = merge(l->r, r);
    }
    else
    {
        root = r;
        r->l = merge(l, r->l);
    }
    update(root);
    return root;
}

int N, M;
treap* nodes;
treap root = nullptr;
long long* devs, * mans;

int main()
{
    srand(time(0));

    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    fin >> N;

    devs = new long long[N];
    mans = new long long[N];
    nodes = new treap[N];

    for (int i = 0; i < N; ++i)
        fin >> devs[i];
    for (int i = 0; i < N; ++i)
        fin >> mans[i];
    for (int i = 0; i < N; ++i)
    {
        nodes[i] = new node(devs[i], mans[i], i);
        treap l, r;
        split(root, l, r, nodes[i]->value());
        l = merge(l, nodes[i]);
        root = merge(l, r);
    }

    fin >> M;
    for (int j = 0; j < M; ++j)
    {
        int num, skill, power_up;
        fin >> num >> skill >> power_up;

        treap l, ltemp, rtemp, r;
        split(root, l, r, nodes[num - 1]->value());
        splitBySize(l, ltemp, rtemp, l->size - 1);

        if (skill == 1)
        {
            rtemp->dev += power_up;
            rtemp->sum_dev += power_up;
        }
        else
        {
            rtemp->man += power_up;
            rtemp->sum_man += power_up;
        }
        root = merge(ltemp, r);
        split(root, l, r, rtemp->value());
        l = merge(l, rtemp);
        root = merge(l, r);
        splitBySize(root, l, r, N / 2);
        fout << l->sum_man + r->sum_dev << endl;
        root = merge(l, r);
    }

    delete[] devs;
    delete[] mans;
    delete[] nodes;

    fin.close();
    fout.close();

    return 0;
}