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
    ListNode* appendTo(ListNode* last, int val, bool& isHead) {
      if (!last) {
        last = new ListNode(val);
        isHead = true;
        return last;
      } else {
        last->next = new ListNode(val);
        isHead = false;
        return last->next;
      }
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      ListNode* ans = NULL; 
      ListNode* ret = NULL;
      int increment = 0;
      while(l1 || l2 || increment) {
        int value = increment;
        if (l1) {
          value += l1->val;
          l1 = l1->next;
        }
        if (l2) {
          value += l2->val;
          l2 = l2->next;
        }
        increment = value / 10;
        value %= 10;
        bool isHead;
        ans = appendTo(ans, value, isHead);
        if (isHead) {
          ret = ans;
        }
      }
      return ret;
    }
};