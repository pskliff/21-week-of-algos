//#include <iostream>
//#include <vector>
//
//
//using namespace std;
//
//
//struct ListNode
//{
//    int val;
//    ListNode* next;
//
//
//    ListNode(int x) : val(x), next(NULL)
//    {}
//};
//
//
//ListNode* reverseList(ListNode* head)
//{
//    if(!head)
//        return head;
//    ListNode* curr = head;
//    ListNode* nxt = head->next;
//    head->next = nullptr;
//
//    while(nxt)
//    {
//        ListNode* buf = nxt->next;
//        nxt->next = curr;
//        curr = nxt;
//        nxt = buf;
//    }
//
//    return curr;
//}
//
//
//int main()
//{
//
//    ListNode* one = new ListNode(1);
//    ListNode* two = new ListNode(2);
//    ListNode* three = new ListNode(3);
//    ListNode* four = new ListNode(4);
//    one->next = two;
//    two->next = three;
//    three->next = four;
//
//    ListNode* curr = one;
//    while(curr)
//    {
//        cout << curr->val << " ";
//        curr = curr->next;
//    }
//    ListNode * n_head = reverseList(one);
//    curr = n_head;
//    cout << endl;
//    while(curr)
//    {
//        cout << curr->val << " ";
//        curr = curr->next;
//    }
//    return 0;
//}