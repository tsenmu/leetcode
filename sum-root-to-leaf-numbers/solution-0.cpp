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
  void dfs(TreeNode* root, int accumulation, int& sum) {
    if (root == NULL) {
      return;
    }

    accumulation *= 10;
    accumulation += root->val;

    if (root->left == NULL && root->right == NULL) {
      sum += accumulation;
    }

    dfs(root->left, accumulation, sum);
    dfs(root->right, accumulation, sum);
  }

  int sumNumbers(TreeNode* root) {
    int sum;
    dfs(root, 0, sum);
    return sum;
  }
};