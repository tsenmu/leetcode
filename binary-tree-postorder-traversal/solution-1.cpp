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
    stack<pair<TreeNode*, bool>> S;
    TreeNode* current = root;
    while (current || !S.empty()) {
      if (current) {
        S.push(make_pair(current, false));
        current = current->left;
      } else {
        current = S.top().first;
        bool status = S.top().second;
        S.pop();
        if (status) {
          ans.push_back(current->val);
          current = NULL;
        } else {
          S.push(make_pair(current, true));
          current = current->right;
        }
      }
    }
    return ans;
  }
};