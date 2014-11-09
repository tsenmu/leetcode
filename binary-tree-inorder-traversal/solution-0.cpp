class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> S;
        TreeNode* node = root;
        while(!S.empty() || node) {
          if (node) {
            S.push(node);
            node = node->left;
          } else {
            node = S.top();
            S.pop();
            result.push_back(node);
            node = node->right;
          }
        }
        return result;
    }
};
