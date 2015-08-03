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
  bool dfs(TreeNode* root, int sum, int accumulation) {
    if (root == NULL) {
      return false;
    }
    if (root->left == NULL && root->right == NULL) {
      if (sum == accumulation + root->val) {
        return true;
      } 
      return false;
    }
    return dfs(root->left, sum, accumulation + root->val) || 
      dfs(root->right, sum, accumulation + root->val);
  }

  bool hasPathSum(TreeNode* root, int sum) {
    return dfs(root, sum, 0);
  }
};