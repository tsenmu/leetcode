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
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL) {
      return NULL;
    }

    ListNode* last = head;
    ListNode* current = head->next;
    while(current) {
      if (current->val == last->val) {
        last->next = current->next;
        delete current;
        current = last->next;
      } else {
        last = current;
        current = current->next;
      }
    }
    return head;
  }
};