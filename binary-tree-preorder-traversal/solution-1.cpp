/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
      vector<int> result;
      stack<TreeNode*> S;
      TreeNode* node = root;
      while(!S.empty() || node) {
        if (node) {
          result.push_back(node->val);
          S.push(node);
          node = node->left;
        } else {
          node = S.top();
          S.pop();
          node = node->right;
        }
      }
      return result;
    }
};
