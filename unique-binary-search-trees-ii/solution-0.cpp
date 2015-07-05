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
private: 
  vector<TreeNode*> constructTree(int l, int r) {
    vector<TreeNode*> ans;
    if (l > r) {
      ans.push_back(NULL);
      return ans;
    }
    for (int i = l; i <= r; ++i) {
      vector<TreeNode*> leftNodes = constructTree(l, i - 1);
      vector<TreeNode*> rightNodes = constructTree(i + 1, r);
      for (int li = 0; li < leftNodes.size(); ++li) {
        for (int ri = 0; ri < rightNodes.size(); ++ri) {
          TreeNode* root = new TreeNode(i); 
          root->left = leftNodes[li];
          root->right = rightNodes[ri];
          ans.push_back(root);
        }
      }
    }
    return ans;
  }
public:
  vector<TreeNode*> generateTrees(int n) {
    return constructTree(1, n); 
  }
};