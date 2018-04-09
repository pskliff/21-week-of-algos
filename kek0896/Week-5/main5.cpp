/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{

public:
    ListNode *detectCycle(ListNode *head)
    {

        if (!head || !head->next || !head->next->next) return nullptr;
        ListNode *turty = head->next;
        ListNode *bunny = head->next->next;

        //Step 1
        while (turty != bunny)
        {
            if (!bunny->next || !bunny->next->next) return nullptr;
            turty = turty->next;
            bunny = bunny->next->next;
        }
        turty = head;

        //Step 2 (not sure, i really got it, but i promise i'll catch up)
        while (turty != bunny)
        {
            turty = turty->next;
            bunny = bunny->next;
        }

        return turty;

    }
};