/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

        if (head == NULL) {
            return NULL;
        }


        RandomListNode* node = head;
        while (node != NULL) {
            // Make a reference to the next of the current node.
            RandomListNode* nodeNext = node->next;

            // Deep clone the current node.
            RandomListNode* duplicateNode = clone(originalNext);

            // Insert the duplicate node after the current node.
            node->next = duplicateNode;
            duplicateNode->next = nodeNext;

            // Iterate to the next node.
            node = nodeNext;
        }

        node = head;
        while (node != NULL) {
            RandomListNode* duplcateNode = node->next;
            if (node->random != NULL) {
                duplcateNode->random = node->random->next;
            } 
            node = duplicateNode->next;
        }

        node = head;
        RandomListNode* newHead = head->next;
        RandomListNode* newNode = newHead;
        
        while (node != NULL) {
            node->next = newNode->next;
            newNode->next = node->next->next;

            node = node->next;
            newNode->next = newNode->next;
        }

        return newHead;
    }

    RandomListNode* clone(RandomListNode* node) {
        return new RandomListNode(node->label);
    }
};