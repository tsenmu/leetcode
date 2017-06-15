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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);        
        dummy->next = head;

        ListNode* current = head;
        ListNode* last = dummy;
        while (current != nullptr) {
            if (current->val == val) {
                last->next = current->next;
                delete current;
                current = last->next;
            }  else {
                last = current;
                current = current->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};