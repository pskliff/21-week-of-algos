#include "list_helpers.h"
#include <algorithm>

using namespace std;

Node* findIntersect(Node* root1, Node* root2)
{
    int l1 = length(root1), l2 = length(root2);
    if(l1 - l2 > 0) {
        for(int i = 0, n = l1 - l2; i < n; ++i)
            root1 = root1->next;
    } else {
        for(int i = 0, n = l2 - l1; i < n; ++i)
            root2 = root2->next;
    }

    for(int i = 0, n = min(l1, l2); i < n; ++i) {
        if(root1 == root2)
            return root1;
        root1 = root1->next;
        root2 = root2->next;
    }
    return nullptr;
}

int main()
{
    pair<Node*, Node*> roots = readIntersectedList();
    Node* intersect = findIntersect(roots.first, roots.second);
    if(intersect == nullptr) {
        cout << -1;
        return 0;
    }
        
    cout << intersect->val;
    Node* cNode = roots.second;
    for(; cNode->next != intersect; cNode = cNode->next);
    cNode->next = nullptr;
    delete roots.first;
    delete roots.second;
    return 0;
}

