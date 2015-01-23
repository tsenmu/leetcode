class Solution {
public:
		vector<string> ans;
		void dfs(int n, int l, int r, int eval, string status) {
			if (l > n || r > n) {
				return;
			}
			if (n == l && n == r) {
				if (eval == 0) {
					ans.push_back(status);
				}
				return;
			}
			if (eval == 0) {
				dfs(n, l + 1, r, eval + 1, status + "(");
			} else {
				dfs(n, l + 1, r, eval + 1, status + "(");
				dfs(n, l, r + 1, eval - 1, status + ")");
			}
		}
    vector<string> generateParenthesis(int n) {
    	ans.clear();
    	dfs(n, 0, 0, 0, "");
			return ans; 
    }
};