/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  bool dfs(TreeNode* l, TreeNode* r) {
    if (l == NULL && r == NULL) {
      return true;
    }
    if (l != NULL && r != NULL && l->val == r->val) {
      return dfs(l->left, r->right) && dfs(l->right, r->left);
    } 
    return false;
  }

  bool isSymmetric(TreeNode* root) {
    if (root == NULL) {
      return true;
    }
    return dfs(root->left, root->right); 
  }
};