//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//
//
//using namespace std;
//
//typedef long long lng;
//typedef pair<lng, int> pair_type;
//
//const int INF = 2e6;
//
//
//
//class Vertex
//{
//public:
//    Vertex* lft, * rght;
//    lng first, second, first_sum, second_sum;
//    int sz, val, key;
//
//
//    Vertex(lng a, lng b, int id) : first(a), second(b), first_sum(a), second_sum(b), sz(1), val(id), key(rand()),
//                                   lft(nullptr), rght(nullptr)
//    {}
//
//
//    pair_type value()
//    {
//        return make_pair(first - second, val);
//    }
//};
//
//
//typedef Vertex* abkureno;
//
//
//int get_sz(abkureno current)
//{
//    return !current ? 0 : current->sz;
//}
//
//
//lng get_first_sum(abkureno current)
//{
//    return !current ? 0 : current->first_sum;
//}
//
//
//lng get_second_sum(abkureno current)
//{
//    return !current ? 0 : current->second_sum;
//}
//
//
//
//void count_sum(abkureno current)
//{
//    if (!current)
//        return;
//    current->sz = get_sz(current->lft) + get_sz(current->rght) + 1;
//    current->first_sum = get_first_sum(current->lft) + get_first_sum(current->rght) + current->first;
//    current->second_sum = get_second_sum(current->lft) + get_second_sum(current->rght) + current->second;
//
//}
//
//
//abkureno merge(abkureno less, abkureno greater)
//{
//    if (!less)
//        return greater;
//    if (!greater)
//        return less;
//
//    abkureno root;
//
//    if (less->key <= greater->key)
//        root = greater, greater->lft = merge(less, greater->lft);
//
//    else
//        root = less, less->rght = merge(less->rght, greater);
//    count_sum(root);
//    return root;
//}
//
//
//void split_size(abkureno root, abkureno& less, abkureno& greater, int sz)
//{
//    if (!root)
//    {
//        less = nullptr;
//        greater = nullptr;
//        return;
//    }
//    if (get_sz(root->lft) + 1 > sz)
//        greater = root, split_size(greater->lft, less, greater->lft, sz);
//    else
//        less = root, split_size(less->rght, less->rght, greater, sz - get_sz(root->lft) - 1);
//    count_sum(root);
//}
//
//
//void split(abkureno root, abkureno& less, abkureno& greater, pair_type val)
//{
//    if (!root)
//    {
//        less = nullptr;
//        greater = nullptr;
//        return;
//    }
//
//    if (root->value() > val)
//        greater = root, split(greater->lft, less, greater->lft, val);
//    else
//        less = root, split(less->rght, less->rght, greater, val);
//    count_sum(root);
//}
//
//
//
//int n, m;
//lng a[INF], b[INF];
//
//abkureno vertices[INF], root = nullptr;
//
//
//int main()
//{
//    srand(time(0));
//    cin >> n;
//    for (int i = 0; i < n; ++i)
//        cin >> a[i];
//    for (int i = 0; i < n; ++i)
//        cin >> b[i];
//
//
//    for (int i = 0; i < n; ++i)
//    {
//        vertices[i] = new Vertex(a[i], b[i], i);
//        abkureno lft, rght;
//        split(root, lft, rght, vertices[i]->value());
//        root = merge(merge(lft, vertices[i]), rght);
//    }
//
//    cin >> m;
//    for (int i = 0; i < m; ++i)
//    {
//        int id, tp, change_val;
//        cin >> id >> tp >> change_val;
//
//        abkureno lft, lft_crop, rght_crop, rght;
//        split(root, lft, rght, vertices[id - 1]->value());
//        split_size(lft, lft_crop, rght_crop, lft->sz - 1);
//
//        if (tp != 1)
//            rght_crop->second += change_val, rght_crop->second_sum += change_val;
//        else
//            rght_crop->first += change_val, rght_crop->first_sum += change_val;
//
//        root = merge(lft_crop, rght);
//        split(root, lft, rght, rght_crop->value());
//        root = merge(merge(lft, rght_crop), rght);
//        split_size(root, lft, rght, n / 2);
//
//        cout << lft->second_sum + rght->first_sum << endl;
//        root = merge(lft, rght);
//    }
//    return 0;
//}