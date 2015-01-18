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
		bool dfs(TreeNode* node, int& depth) {
			if (node == NULL) {
				depth = 0;
				return true;
			}
			int depthLeft, depthRight;
			bool isBalancedLeft, isBalancedRight;
			isBalancedLeft = dfs(node->left, depthLeft);
			isBalancedRight = dfs(node->right, depthRight);
			if (! (isBalancedLeft && isBalancedRight)) {
				return false;
			}
			depth = max(depthLeft, depthRight) + 1;
			int depthDelta = abs(depthLeft - depthRight);
			if (depthDelta > 1) {
				return false;
			} else {
				return true;
			}
		}
    bool isBalanced(TreeNode *root) { 
    	int depth;
    	return dfs(root, depth);
    }
};