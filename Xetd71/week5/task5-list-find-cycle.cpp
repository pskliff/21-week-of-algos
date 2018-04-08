#include "list_helpers.h"
using namespace std;

Node* findCycle(Node* root) {
    if(!root->next || !root->next->next)
        return nullptr;

    Node* i = root->next;
    Node* j = i->next;
    while(i != j) {
        if(!j->next || !j->next->next)
            return nullptr;
        i = i->next;
        j = j->next->next;
    }

    j = root;
    while(i != j) {
        i = i->next;
        j = j->next;
    }
    return i;
}

int main()
{
    Node* root = readCyclicList();
    Node* cyclic = findCycle(root);
    if(cyclic == nullptr) {
        cout << -1;
        return 0;
    }

    Node* cNode = cyclic;
    for(; cNode->next != cyclic; cNode = cNode->next);
    cNode->next = nullptr;

    cout << cyclic->val;
    delete root;
    return 0;
}