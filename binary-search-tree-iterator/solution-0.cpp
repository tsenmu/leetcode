/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    vector<int> state;
    int depth;
    TreeNode* current_node;
public:
    BSTIterator(TreeNode *root) {
        current_node = root;
        depth = -1;
        while (current_node) {
            state.push_back(0);
            depth++;
            current_node = current_node->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return current_node != NULL; 
    }

    /** @return the next smallest number */
    int next() {
        int ret = current_node->val;  

        if (state[depth] == 0) {
            
        } else if (state[depth] == 1) {

        } else {
            
        }

        return ret;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */