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


int getListLen(ListNode *head)
{
    ListNode *it = head;
    int len = 0;
    while(it != nullptr)
    {
        ++len;
        it = it->next;
    }
    return len;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int lenA = getListLen(headA), lenB = getListLen(headB);
    int diff = lenA - lenB;

    if(diff >= 0)
        for (int i = 0; i < diff; ++i)
            headA = headA->next;

    else
        for (int i = 0; i < -diff; ++i)
            headB = headB->next;

    while(headA != nullptr && headB != nullptr)
    {
        if(headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }

    return nullptr;
}

int main()
{
    int n1, n2, intersect;
    //n1 > n2
    //intersect - index of intersection of bigger list

    cin >> n1 >> n2 >> intersect;

    ListNode *headA = new ListNode(1);
    ListNode *headB = new ListNode(1);


    ListNode *currA = headA;
    ListNode *currB = headB;

    for (int i = 0; i < intersect; ++i) {
        currA->next = new ListNode(i + 2);
        currA = currA->next;
    }

    for (int i = 0; i < intersect - (n1 - n2); ++i) {
        currB->next = new ListNode(i + 2);
        currB = currB->next;
    }

    ListNode *temp = new ListNode(intersect);
    currA->next = temp;
    currB->next = temp;

    currA = currA->next;
    for (int i = 0; i < n1 - intersect - 1; ++i) {
        currA->next = new ListNode(intersect + i + 1);
        currA = currA->next;
    }

    temp = getIntersectionNode(headA, headB);
    if(temp == nullptr)
        cout << "No intersection";
    else
        cout << temp->val;


}