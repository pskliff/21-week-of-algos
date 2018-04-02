#include <iostream>
#include <ctime>
using namespace std;

struct Node
{
    Node(long long a, long long b, int id):
            a(a), b(b), sumA(a), sumB(b), size(1), id(id), key(rand()), l(nullptr), r(nullptr) {}

    pair <long long, int> value() {
        return make_pair(a - b, id);
    }

    Node *l, *r;
    long long a, b, sumA, sumB;
    int size, id, key;
};

typedef Node* tNode;

long long getSumA(tNode cur) {
    return (cur == nullptr) ? 0 : cur->sumA;
}

long long getSumB(tNode cur) {
    return (cur == nullptr) ? 0 : cur->sumB;
}

int getSize(tNode cur) {
    return (cur == nullptr) ? 0 : cur->size;
}

void recount(tNode cur) {
    if (cur == nullptr)
        return;
    cur->sumA = getSumA(cur->l) + getSumA(cur->r) + cur->a;
    cur->sumB = getSumB(cur->l) + getSumB(cur->r) + cur->b;
    cur->size = getSize(cur->l) + getSize(cur->r) + 1;
}

void split(tNode root, tNode & l, tNode & r, pair <long long, int> val) {
    if (root == nullptr) {
        l = r = nullptr;
        return;
    }
    if (root->value() > val)
        r = root, split(r->l, l, r->l, val);
    else
        l = root, split(l->r, l->r, r, val);
    recount(root);
}

void splitBySize(tNode root, tNode & l, tNode & r, int size) {
    if (root == nullptr) {
        l = r = nullptr;
        return;
    }
    if (getSize(root->l) + 1 > size)
        r = root, splitBySize(r->l, l, r->l, size);
    else
        l = root, splitBySize(l->r, l->r, r, size - getSize(root->l) - 1);
    recount(root);
}

tNode merge(tNode l, tNode r) {
    if (l == nullptr)
        return r;
    if (r == nullptr)
        return l;
    tNode root;
    if (l->key <= r->key) {
        root = r;
        r->l = merge(l, r->l);
    } else {
        root = l;
        l->r = merge(l->r, r);
    }
    recount(root);
    return root;
}

const int nMax = 2e5;
int n, m;
tNode nodes[nMax], root = nullptr;
long long a[nMax], b[nMax];

int main()
{
    srand(time(0));
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i) {
        nodes[i] = new Node(a[i], b[i], i);
        tNode l, r;
        split(root, l, r, nodes[i]->value());
        root = merge(merge(l, nodes[i]), r);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int num, type, d;
        cin >> num >> type >> d;
        tNode l, lm, rm, r;
        split(root, l, r, nodes[num - 1]->value());
        splitBySize(l, lm, rm, l->size - 1);
        if (type == 1)
            rm->a += d, rm->sumA += d;
        else
            rm->b += d, rm->sumB += d;
        root = merge(lm, r);
        split(root, l, r, rm->value());
        root = merge(merge(l, rm), r);
        splitBySize(root, l, r, n / 2);
        cout << l->sumB + r->sumA << endl;
        root = merge(l, r);
    }
    return 0;
}