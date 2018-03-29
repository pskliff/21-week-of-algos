#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll, int> valueType;

struct node
{
    node* l, * r;
    ll a, b, sum_a, sum_b;
    int size, id, key;

    node(ll a, ll b, int id) : a(a), b(b), sum_a(a), sum_b(b), size(1), id(id), key(rand()), l(nullptr), r(nullptr)
    {}

    valueType value()
    {
        return make_pair(a - b, id);
    }
};

typedef node* treap;

void split(treap root, valueType val, treap &l, treap &r)
{
    if (root == nullptr)
        return void(l = r = nullptr);
    if (root->value() <= val)
        l = root, split(l->r, )

}

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    int N;
    fin >> N;
    int a[N], b[N];

    for (int i = 0; i < N; ++i)
        fin >> a[i];
    for (int i = 0; i < N; ++i)
        fin >> b[i];


    fin.close();
    fout.close();

    return 0;
}