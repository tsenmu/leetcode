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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL) {
      return NULL;
    }
    ListNode d = 0;
    ListNode* dummy = &d;
    dummy->next = head;
    ListNode* fast = dummy;
    ListNode* slow = dummy;

    while (n--) {
      fast = fast->next;
    } 

    while (fast && fast->next) {
      fast = fast->next;
      slow = slow->next;
    }

    fast = slow->next;
    slow->next = slow->next->next;

    if (fast == head) {
      head = fast->next;
    }
    delete fast;

    return head;
  }
};