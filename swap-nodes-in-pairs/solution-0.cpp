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
    ListNode *swapPairs(ListNode *head) {
    	if (head == NULL) {
    		return head;
    	}
     	// Initialise
			ListNode* front = head;
			ListNode* end = NULL;
			ListNode* ret = front->next == NULL ? front : front->next;
			ListNode* previous = NULL;
			while (front != NULL) {
				end = front->next;
				if (end == NULL) {
					break;
				} else {
					// Perform the swap
					front->next = end->next;
					end->next = front;
					if (previous != NULL) {
						previous->next = end;
					}
					previous = front;
					front = front->next;
				}

			}
			return ret;
    }
};