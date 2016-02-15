class Solution {
protected:
    void dfs(const string& preorder, int& index) {
        
        const int n = preorder.length();
        
        if (index >= n) {
            return;
        }

        if (preorder[index] == '#') {
            return;
        }
        
        for (int i = 0; i < 2; ++i) {
            while (index < n && (isdigit(preorder[index]) || preorder[index] == '#') ) {
                index++;
            }
            index++;
            dfs(preorder, index);
        }
    }
public:

    bool isValidSerialization(string preorder) {
        int index = 0;
        dfs(preorder, index);
        return preorder.length() - 1 == index;
    }
};

