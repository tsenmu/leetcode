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

    TreeNode* locate(int code, TreeNode* root, int depth) {
        TreeNode* ans = root;
        for (int i = depth - 1; i >= 0; --i) {
            if (code & (1 << i)) { // right
                ans = ans->right;
            } else { //left
                ans = ans->left;
            }
        }
        return ans;
    }

    int countNodes(TreeNode* root) {
        TreeNode* node = root;
        int height = 0;
        while (node) {
            node = node->left; 
            height++;
        } 
        if (height < 2) {
            return height;
        } 
        // printf("height = %d\n", height);
        int n = 1;
        for (int i = 0; i < height - 2; ++i) {
            n *= 2;
        }
        // printf("n = %d\n", n);

        // binary search
        int l = 0; 
        int r = n - 1;
        int m = 0;

        while (l < r) {
            m = l + ((r - l) >> 1);
            // printf("m = %d\n", m);
            node = locate(m, root, height - 2);
            if (node->left && node->right) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        node = locate(r, root, height - 2);

        int ans = n * 2 - 1 + r * 2;

        if (node->left && node->right) {
            ans += 2;
        } else if (node->left) {
            ans += 1;
        }

        return ans;
    }
};