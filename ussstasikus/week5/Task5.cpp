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


ListNode *detectCycle(ListNode *head)
{
    ListNode *sp, *fp;

    sp = head->next;
    if(!sp)
        return nullptr;
    fp = head->next->next;

    while(sp != fp)
    {
        if(!sp->next || !fp->next || !fp->next->next)
            return nullptr;
        sp = sp->next;
        fp = fp->next->next;
    }
    sp = head;
    while(sp != fp)
    {
        sp = sp->next;
        fp = fp->next;
    }
    return sp;
}

int main()
{
    int n, loop_start;
    cin >> n >> loop_start;

    int x;
    cin >> x;
    ListNode *head = new ListNode(x);
    ListNode *curr = head;
    ListNode *loop_ind;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x;
        curr->next = new ListNode(x);
        if(i + 1 == loop_start)
            loop_ind = curr->next;
        curr = curr->next;
    }
    curr->next = loop_ind;

    loop_ind = detectCycle(head);
    if(!loop_ind)
        cout << "No cycle";
    else
        cout << loop_ind->val;

}
