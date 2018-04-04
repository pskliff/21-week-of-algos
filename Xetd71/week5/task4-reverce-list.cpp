#include "list_helpers.h"
using namespace std;

Node* reverseList(Node* root) {
    Node* n1 = root;
    Node* n2 = root->next;
    Node* n3;
    n1->next = nullptr;
    while(n2 != nullptr) {
        n3 = n2->next;
        n2->next = n1;
        n1 = n2;
        n2 = n3;
    }
    return n1;
}

int main()
{
    Node* root = readList();
    root = reverseList(root);
    printList(root);
    delete root;
    return 0;
}