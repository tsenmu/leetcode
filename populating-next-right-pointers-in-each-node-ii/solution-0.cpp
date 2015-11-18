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
    TreeLinkNode* firstChild = NULL;
    TreeLinkNode* previousValidChild = NULL;
    while (current) {
      if (current->left && current->right) {
        current->left->next = current->right;
        if (previousValidChild) {
          previousValidChild->next = current->left;
        }
        previousValidChild = current->right;
        if (!firstChild) {
          firstChild = current->left;
        }
      } else if (current->left) {
        if (previousValidChild) {
          previousValidChild->next = current->left;
        }
        previousValidChild = current->left;
        if (!firstChild) {
          firstChild = current->left;
        }
      } else if (current->right) {
        if (previousValidChild) {
          previousValidChild->next = current->right;
        }
        previousValidChild = current->right;
        if (!firstChild) {
          firstChild = current->right;
        }
      }
      if (current->next) {
        current = current->next; 
      } else if (firstChild) {
        current = firstChild;
        firstChild = NULL;
        previousValidChild = NULL;
      } else {
        current = NULL;
      }
    }
  }
};