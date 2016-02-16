/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
protected:
    static bool cmp(ListNode* a, ListNode* b) {
        return a->val > b->val;  
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;

        priority_queue<ListNode, vector<ListNode*>, decltype(&cmp)> heap(&cmp);

        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                heap.push(lists[i]);
            }
        }

        while (!heap.empty()) {
            ListNode* top = heap.top();
            heap.pop();
            node->next = top;
            node = node->next;
            if (top->next) {
                heap.push(top->next);
            }
            node->next = NULL;
        }

        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
    }
};