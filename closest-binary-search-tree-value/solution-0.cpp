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

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        int closest = root->val;
        if (target < root->val && root->left) {
            int leftClosest = closestValue(root->left, target);
            if (fabs(target - leftClosest) < fabs(target - closest)) {
                closest = leftClosest;
            }
        }

        if (target > root->val && root->right) {
            int rightClosest = closestValue(root->right, target);
            if (fabs(target - rightClosest) < fabs(target - closest)) {
                closest = rightClosest;
            }
        }

        return closest;
    }
};