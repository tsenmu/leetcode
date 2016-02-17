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
protected:
    void dfs(TreeNode* root, int cur, int& ans) {
        ans = max(ans, cur);
        if (root->left) {
            if (root->left->val - root->val == 1) {
                dfs(root->left, cur + 1, ans);
            } else {
                dfs(root->left, 1, ans);
            }
        }

        if (root->right) {
            if (root->right->val - root->val == 1) {
                dfs(root->right, cur + 1, ans);
            } else {
                dfs(root->right, 1, ans);
            }
        }
    }
public:
    int longestConsecutive(TreeNode* root) {
        if (root == NULL)  {
            return 0;
        }

        int ans = 1;
        dfs(root, 1, ans);
        return ans;
    }
};