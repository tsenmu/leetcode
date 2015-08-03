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
  bool dfs(long long minimum, long long maximum, TreeNode* root) {
    if (!root) {
      return true;
    }

    if (root->val <= minimum || root->val >= maximum) {
      return false;
    }

    bool result = true;
    if (root->left) {
      result &= dfs(minimum, root->val, root->left);
    }
    if (root->right) {
      result &= dfs(root->val, maximum, root->right);
    }
    return result;
  }
  bool isValidBST(TreeNode* root) {
    dfs(, INT_MAX, root);
  }
};