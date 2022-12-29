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
    ListNode *detectCycle(ListNode *head) {

        if(head == NULL)
            return NULL;
        
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) {
                ListNode *slow2 = head;
                while(slow2 != slow) {
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};