/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head == NULL) return head;
        ListNode* newhead = new ListNode(head->val);
        while(head->next != NULL){
            head = head->next;
            ListNode* newnewhead = new ListNode(head->val);
            newnewhead->next = newhead;
            newhead = newnewhead;
        }
        return newhead;

    }
};