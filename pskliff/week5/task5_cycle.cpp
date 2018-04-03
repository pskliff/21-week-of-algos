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
//ListNode* detectCycle(ListNode* head)
//{
//    ListNode* slow = head, * fast = head;
//    int f_count = 0, s_count = 0;
//
//    while (fast)
//    {
//        fast = fast->next;
//        if (!fast)
//            return NULL;
//        fast = fast->next;
//        f_count += 2;
//        slow = slow->next;
//        s_count++;
//        if (fast == slow)
//            break;
//    }
//
//
//    if (!fast) return NULL;
//
//    slow = head;
//    while (fast != slow)
//    {
//        slow = slow->next;
//        fast = fast->next;
//    }
//
//    return slow;
//}
//
//
//int main()
//{
//    ListNode* one = new ListNode(1);
////    ListNode* two = new ListNode(2);
////    ListNode* three = new ListNode(3);
////    ListNode* four = new ListNode(4);
////    one->next = two;
////    two->next = three;
////    three->next = four;
//
//    ListNode* curr = one;
//    while (curr)
//    {
//        cout << curr->val << " ";
//        curr = curr->next;
//    }
//
//    cout << endl << (detectCycle(one) ? "num" : "null");
//    return 0;
//}