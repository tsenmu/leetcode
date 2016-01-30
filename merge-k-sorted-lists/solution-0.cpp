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
    bool cmp(const pair<int, ListNode*>>& a, const pair<int, ListNode*>>& b) {
        return a.first < b.first;  
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>, cmp> Q;

        return NULL;
    }
};