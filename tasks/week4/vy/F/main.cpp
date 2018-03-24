#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair <ll, int> valueType;

struct tNode {
	tNode *l, *r;
	ll a, b, sum_a, sum_b;
	int size, id, key;
	tNode(ll a, ll b, int id): 
	a(a), b(b), sum_a(a), sum_b(b), size(1), id(id), key(rand()), l(nullptr), r(nullptr) {}
	valueType value() {
		return make_pair(a - b, id);
	}
};

typedef tNode* treap;

ll getSumA(treap cur) {
	return (cur == nullptr) ? 0 : cur->sum_a;
}

ll getSumB(treap cur) {
	return (cur == nullptr) ? 0 : cur->sum_b;
}

int getSize(treap cur) {
	return (cur == nullptr) ? 0 : cur->size;
}

void recount(treap cur) {
	if (cur == nullptr)
		return;
	cur->sum_a = getSumA(cur->l) + getSumA(cur->r) + cur->a;
	cur->sum_b = getSumB(cur->l) + getSumB(cur->r) + cur->b;
	cur->size = getSize(cur->l) + getSize(cur->r) + 1;
}

void split(treap root, treap & l, treap & r, valueType val) {
	if (root == nullptr)
		return void(l = r = nullptr);
	if (root->value() <= val)
		l = root, split(l->r, l->r, r, val);
	else
		r = root, split(r->l, l, r->l, val);
	recount(root);
}

void splitBySize(treap root, treap & l, treap & r, int size) {
	if (root == nullptr)
		return void(l = r = nullptr);
	if (getSize(root->l) + 1 <= size)
		l = root, splitBySize(l->r, l->r, r, size - getSize(root->l) - 1);
	else
		r = root, splitBySize(r->l, l, r->l, size);
	recount(root);
} 

treap merge(treap l, treap r) {
	if (l == nullptr || r == nullptr)
		return l ? l : r;
	treap root;
	if (l->key > r->key)
		root = l, l->r = merge(l->r, r);
	else
		root = r, r->l = merge(l, r->l);
	recount(root);
	return root;
}

const int MAXN = 2e5;

int n, m;
treap nodes[MAXN], root = nullptr;
ll a[MAXN], b[MAXN];

void outNode(treap cur) {
	if (cur == nullptr)
		cout << "null";
	else
		cout << "(" << cur->value().first << "; " << cur->id << ")";
}

void output(treap cur) {
	if (cur == nullptr)
		return;
	outNode(cur->l);
	cout << " <- ";
	outNode(cur);
	cout << " -> ";
	outNode(cur->r);
	cout << endl;
	output(cur->l);
	output(cur->r);
}

int main() {
	srand(time(0));
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	for (int i = 0; i < n; ++i) {
		nodes[i] = new tNode(a[i], b[i], i);
		treap l, r;
		split(root, l, r, nodes[i]->value());
		root = merge(merge(l, nodes[i]), r);
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int num, type, d;
		cin >> num >> type >> d;
		treap l, lm, rm, r;
		split(root, l, r, nodes[num - 1]->value());
		splitBySize(l, lm, rm, l->size - 1);
		if (type == 1)
			rm->a += d, rm->sum_a += d;
		else
			rm->b += d, rm->sum_b += d;
		root = merge(lm, r);
		split(root, l, r, rm->value());
		root = merge(merge(l, rm), r);
		splitBySize(root, l, r, n / 2);
		cout << l->sum_b + r->sum_a << endl;
		root = merge(l, r);
	}
	cin >> n;
	return 0;
}