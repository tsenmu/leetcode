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
    if (head == NULL) {
      return NULL;
    }
    stack<ListNode*> s;       
    ListNode* current = head;
    while(current) {
      s.push(current);
      current = current->next;
    }
    head = s.top();
    s.pop();
    last = head;
    while(!s.empty()) {
      current = s.top();   
      last->next = current;
      last = current;
    }
    if (current != NULL) {
      current->next = NULL;
    }
    return head;
  }
};