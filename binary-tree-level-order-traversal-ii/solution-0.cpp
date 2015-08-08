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
  vector<vector<int>> levelOrder(TreeNode* root) {
    queue<pair<TreeNode*, int> >  Q;
    Q.push(make_pair(root, 0));
    vector<vector<int>> ans;
    while (!Q.empty()) {
      const TreeNode* current = Q.front().first;
      const int level = Q.front().second;
      if (current != NULL) {
        if (level >= ans.size()) {
          ans.push_back(vector<int>());
        }
        ans[level].push_back(current->val);
        Q.push(make_pair(current->left, level + 1));
        Q.push(make_pair(current->right, level + 1));
      }
      Q.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};