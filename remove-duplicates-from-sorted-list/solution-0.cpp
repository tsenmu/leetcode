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
    ListNode *deleteDuplicates(ListNode *head) {
      ListNode *last = 0;
      ListNode *cur = head;
      while (cur) {
        if (last && cur->val == last->val) {
          cur = cur->next;
          delete last->next;
          last->next = cur;
        } else {
          last = cur;
          cur = cur->next;
        }
      }

    }
};
