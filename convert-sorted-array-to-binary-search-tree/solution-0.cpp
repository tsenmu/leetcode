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
    TreeNode* constructBST(vector<int>& num, int l, int r) {
      TreeNode* node = 0;
      int m = 0;
      if (l <= r) {
        m = (l + r) >> 1;
        node = new TreeNode(num[m]);
        node->left = constructBST(num, l, m - 1);
        node->right = constructBST(num, m + 1, r);
      }
      return node;
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
      return constructBST(num, 0, num.size() - 1);
    }
};
