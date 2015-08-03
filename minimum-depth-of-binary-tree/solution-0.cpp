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
  int dfs(TreeNode* root) {
    if (root == NULL) {
      return INT_MAX;
    }
    if (root->left == NULL && root->right == NULL) {
      return 1;
    }
    return 1 + min(dfs(root->left), dfs(root->right));
  }
  int minDepth(TreeNode* root) {
    int result = dfs(root);
    if (result == INT_MAX) {
      return 0;
    } 
    return result;
  }
};