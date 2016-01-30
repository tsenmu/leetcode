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

    ListNode* removeNext(ListNode* current) {
        if (current == NULL) {
            return NULL;
        }
        ListNode* ret = current->next;
        if (ret) {
            current->next = ret->next;
            ret->next = NULL;
        } else {
            current->next = NULL;
        }
        return ret;
    }

    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return head;
        }

        ListNode* evenHead = new ListNode(0);

        ListNode* oddCurrent = head;
        ListNode* evenCurrent = evenHead;
        ListNode* lastOddCurrent = head;

        while (oddCurrent) {
            ListNode* evenNode = removeNext(oddCurrent);
            evenCurrent->next = evenNode;
            if (evenNode) {
                evenCurrent = evenCurrent->next;
            } 
            lastOddCurrent = oddCurrent;
            oddCurrent = oddCurrent->next;
        }

        lastOddCurrent->next = evenHead->next;

        return head;
    }
};