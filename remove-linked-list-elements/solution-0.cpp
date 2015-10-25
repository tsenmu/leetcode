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
    ListNode* current = head;
    ListNode* previous = NULL;
    while (current != NULL) {
      if (current->val == val) {
        if (previous) {
            previous->next = current->next;
            delete current;
            current = previous->next;
        } else {
            head = current->next;
            delete current;
            current = head;
        }
      } else {
          previous = current;
          current = current->next;
      }
    }      

    return head;
  }
};