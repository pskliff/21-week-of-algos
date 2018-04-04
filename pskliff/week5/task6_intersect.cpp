#include <iostream>
#include <vector>


using namespace std;


struct ListNode
{
    int val;
    ListNode* next;


    ListNode(int x) : val(x), next(NULL)
    {}
};


ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
    ListNode* small = headA, *big = headB;
    int lenA = 0, lenB = 0;
    while(small)
    {
        ++lenA;
        small = small->next;
    }
    while (big)
    {
        ++lenB;
        big = big->next;
    }

    if (!lenA || !lenB)
        return nullptr;

    int diff = 0;
    if (lenA > lenB)
    {
        small = headB;
        big = headA;
        diff = lenA - lenB;
    } else{
        small = headA;
        big = headB;
        diff = lenB - lenA;
    }

    for (int i = 0; i < diff; ++i)
        big = big->next;

    while(big)
    {
        if (big == small)
            return big;
        big = big->next;
        small = small->next;
    }
    return nullptr;
}


int main()
{
    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(2);
    ListNode* b1 = new ListNode(3);
    ListNode* b2 = new ListNode(4);
    ListNode* b3 = new ListNode(4);
    ListNode* c1 = new ListNode(4);
    ListNode* c2 = new ListNode(4);
    a1->next = a2;
//    a2->next = c1;
    b1->next = b2;
    b2->next = b3;
//    b3->next = c1;
//    c1->next = c2;

//    ListNode* curr = one;
//    while (curr)
//    {
//        cout << curr->val << " ";
//        curr = curr->next;
//    }

    cout << endl << (getIntersectionNode(a1, b1) ? "num" : "null");
    return 0;
}