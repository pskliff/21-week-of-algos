#ifndef WEEK5_LIST_HELPERS_H
#define WEEK5_LIST_HELPERS_H
#include <iostream>

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
    ~Node() { delete next; }
};

Node* readList() {
    int n, v;
    std::cin >> n >> v;
    Node* root = new Node(v);
    Node* cNode = root;
    for(int i = 1; i < n; ++i) {
        std::cin >> v;
        cNode->next = new Node(v);
        cNode = cNode->next;
    }
    return root;
}

Node* readCyclicList() {
    int n, k, v;
    std::cin >> n >> k >> v;
    Node* root = new Node(v);
    Node* cNode = root;
    for(int i = 1; i < k; ++i) {
        std::cin >> v;
        cNode->next = new Node(v);
        cNode = cNode->next;
    }
    Node* cyclic = cNode;
    for(int i = k; i < n; ++i) {
        std::cin >> v;
        cNode->next = new Node(v);
        cNode = cNode->next;
    }
    cNode->next = cyclic;
    return root;
}

std::pair<Node*, Node*> readIntersectedList() {
    int n1, n2, k, v;
    std::cin >> n1 >> n2 >> k >> v;

    Node* root1 = new Node(v);
    Node* cNode = root1;
    for(int i = 1; i < k; ++i) {
        std::cin >> v;
        cNode->next = new Node(v);
        cNode = cNode->next;
    }
    Node* intersect = cNode;
    for(int i = k; i < n1; ++i) {
        std::cin >> v;
        cNode->next = new Node(v);
        cNode = cNode->next;
    }

    std::cin >> v;
    Node* root2 = new Node(v);
    cNode = root2;
    for(int i = 1; i < n2; ++i) {
        std::cin >> v;
        cNode->next = new Node(v);
        cNode = cNode->next;
    }
    cNode->next = intersect;

    return std::make_pair(root1, root2);
}

int length(Node* root) {
    int n = 0;
    for(Node* cNode = root; cNode != nullptr; cNode = cNode->next)
        ++n;
    return n;
}

void printList(Node* root) {
    for(Node* cNode = root; cNode != nullptr; cNode = cNode->next) {
        std::cout << cNode->val << ' ';
    }
    std::cout << std::endl;
}

#endif //WEEK5_LIST_HELPERS_H
