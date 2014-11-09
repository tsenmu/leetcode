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
    bool hasCycle(ListNode *head) {
      ListNode *p = head;
      ListNode *q = head;
      while(true) {
        p = p ? p->next : 0;
        q = q ? (q->next ? q->next->next : 0) : 0;
        if (!q) return false;
        if (p == q) return true;
      }
    }
};
