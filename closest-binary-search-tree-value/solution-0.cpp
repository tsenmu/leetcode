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
    int closestValue(TreeNode* root, double target) {
        double diff = target - root->val;
        
        if (diff < 0 && root->left != NULL) {
            int leftVal = closestValue(root->left, target);
            return fabs(diff) < fabs(leftVal - target) ? root->val : leftVal;
        } else if (diff > 0 && root->right != NULL) {
            int rightVal = closestValue(root->right, target);
            return fabs(diff) < fabs(rightVal - target) ? root->val : rightVal;
        }
        return root->val;
    }
};