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
    int dfs(TreeNode* root, int length, int& ans) {
        ans = max(ans, length);

        if (root->left) {
            if (root->left->val == root->val + 1) {
                dfs(root->left, length + 1, ans);
            } else {
                dfs(root->left, 1, ans);
            }
        }

        if (root->right) {
            if (root->right->val == root->val + 1) {
                dfs(root->right, length + 1, ans);
            } else {
                dfs(root->right, 1, ans);
            }
        }
    }

    int longestConsecutive(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        ans = 0;

        dfs(root, 1, ans);
        return ans;
    }
};