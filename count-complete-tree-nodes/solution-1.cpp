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

    bool isComplete(TreeNode* node, int level) {
        while (level--) {
            node = node->right;
        }
        return node != NULL;
    }
    int countNodes(TreeNode* root) {
        int height = 0;       
        TreeNode* node = root;
        while (node) {
            node = node->left;
            height++;
        }
        
        if (height < 2) {
            return height;
        }

        int level = height - 2;

        node = root;

        int count = 0;
        while (level >= 0) {
            if (isComplete(node->left, level)) {
                node = node->right; 
                count += (1 << level);
            } else {
                node = node->left;
            }
            level--;
        }

        if (node) {
            count++;
        } 

        return count + (1 << (height - 1)) - 1;

    }
};