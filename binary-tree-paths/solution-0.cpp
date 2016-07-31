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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> resultCollection; 
        dfs(root, "", resultCollection);
        return resultCollection;
    }

    void dfs(TreeNode* node, string result, vector<string>& resultCollection) {
      if (node == NULL) {
        return;
      }

      bool isLeaf = node->left == NULL && node->right == NULL;

      ostringstream oss;
      oss << node->val << (isLeaf ? "" : "->");
      result += oss.str();

      if (isLeaf) {
        resultCollection.push_back(result);
      } else {
        dfs(node->left, result, resultCollection);
        dfs(node->right, result, resultCollection);
      }
    }
};