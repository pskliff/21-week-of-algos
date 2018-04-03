//
// Created by Stas Don on 02/04/2018.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head)
{
    ListNode *it1 = head, *it2 = head->next;

    head->next = nullptr;
    while(it2 != nullptr)
    {
        ListNode *temp = it2->next;
        it2->next = it1;
        it1 = temp;
        temp = it1;
        it1 = it2;
        it2 = temp;
    }
    return it1;

}


int main()
{
    int n, x;
    cin >> n;
    cin >> x;
    ListNode *head = new ListNode(x), *prev = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x;
        ListNode * item = new ListNode(x);
        prev->next = item;
        prev = item;
    }

    head = reverseList(head);

    while(head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

