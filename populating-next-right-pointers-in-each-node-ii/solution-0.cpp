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
      TreeLinkNode* children[] = {current->left, current->right};
      for (int i = 0; i < 2; ++i) {
        TreeLinkNode* child = children[i]; 
        if (child) {
          if (previousChild) {
            previousChild->next = child;
          }
          previousChild = child;
          if (!firstChild) {
            firstChild = child;
          }
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