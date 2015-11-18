/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
  void connect(TreeLinkNode *root) {
    TreeLinkNode* current = root;
    TreeLinkNode* firstChild = NULL; // first child in the layer
    TreeLinkNode* previousChild = NULL; // previous child in the layer
    while (current) {
      if (current->left) {
        if (previousChild) {
          previousChild->next = current->left;
        }
        previousChild = current->left;
        if (!firstChild) {
          firstChild = current->left;
        }
      } 

      if (current->right) {
        if (previousChild) {
          previousChild->next = current->right;
        }
        previousChild = current->right;
        if (!firstChild) {
          firstChild = current->right;
        }
      }
      if (current->next) {
        // go to next
        current = current->next; 
      } else if (firstChild) {
        // go to next layer
        current = firstChild;
        firstChild = NULL;
        previousChild = NULL;
      } else {
        // finish
        current = NULL;
      }
    }
  }
};