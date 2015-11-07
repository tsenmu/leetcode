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
  vector<string> result;

  void dfs(string res, TreeNode* root) {
    if (root == NULL) {
      return;
    } 
    if (!res.empty()) {
      res += "->";
    }
    res += to_string(root->val);

    if (root->left == NULL && root->right == NULL) {
      result.push_back(res);
    }
    dfs(res, root->left);
    dfs(res, root->right);
  }

  vector<string> binaryTreePaths(TreeNode* root) {
    if (root == NULL) {
      return result;
    }
    string str;
    dfs(str, root);
    return result;
  }
};