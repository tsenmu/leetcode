class Solution {
public:

    void dfs(vector<vector<int>>& results, vector<int>& result, 
        int current_num,
        int maximum_num, int maximum_count) {

        if (result.size() == maximum_count) {
            results.push_back(result);
        }

        for (int i = current_num; i <= maximum_num; ++i) {
            result.push_back(i);
            dfs(results, result, i + 1, maximum_num, maximum_count);
            result.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        vector<int> result;

        dfs(results, result, 1, n, k);

        return results;
    }
};