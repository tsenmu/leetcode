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
  void dfs(TreeNode* root, int sum, int accumulation, vector<int> solution) {
    if (root == NULL) {
      return;
    }
    accumulation += root->val;
    solution.push_back(root->val);
    if (root->left == NULL && root->right == NULL) {
      if (accumulation == sum) {
        return solutions.push_back(solution);
      }
    }
    dfs(root->left, sum, accumulation, solution);
    dfs(root->right, sum, accumulation, solution);
  }
  vector<vector<int> > solutions;
  vector<vector<int> > pathSum(TreeNode* root, int sum) {
    solutions.clear(); 
    dfs(root, sum, 0, vector<int>());
    return solutions;
  }
};