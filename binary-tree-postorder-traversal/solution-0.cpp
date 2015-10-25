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
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) {
      return ans;
    } 
    vector<int> leftResult = postorderTraversal(root->left);
    vector<int> rightResult = postorderTraversal(root->right);
    ans.insert(ans.end(), leftResult.begin(), leftResult.end());
    ans.insert(ans.end(), rightResult.begin(), rightResult.end());
    ans.push_back(root->val);
    return ans;
  }
};