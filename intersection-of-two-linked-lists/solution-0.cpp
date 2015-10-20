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
  int len(ListNode* head) {
    int ans = 0;
    while(head != NULL) {
      ans++;
      head = head->next;
    }
    return ans;
  }
  ListNode* seek(ListNode* head, int pos) {
    for (int i = 0; i < pos; ++i) {
      head = head->next;
    }
    return head;
  }
  ListNode* step(ListNode* a, ListNode* b) {
    while(a != NULL && b != NULL) {
      if (a == b) {
        return a;
      } else {
        a = a->next;
        b = b->next;
      }
    }
    return NULL;
  }
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = len(headA);
    int lenB = len(headB);
    if (lenA > lenB) {
      return getIntersectionNode(headB, headA);
    }
    headB = seek(headB, lenB - lenA);
    return step(headA, headB);
  }
};