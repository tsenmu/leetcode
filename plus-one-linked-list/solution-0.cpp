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
    ListNode* plusOne(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* node = dummy;
        
        ListNode* affected = dummy;
        while (node->next) {
            node = node->next;
            if (node->val != 9) {
                affected = node;
            }
        }

        if (node->val == 9) {
            node->val = 0;
        }

        node = affected; 
        node->val += 1;

        while (node->next) {
            node = node->next;
            node->val = 0;
        }

        if (dummy->val == 0) {
            delete dummy;
            return head;
        }

        return dummy;
    }
};