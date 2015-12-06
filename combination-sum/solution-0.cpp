class Solution {
public:
    vector<vector<int>> results;

    void dfs(vector<int>& result, int sum, int lastIndex, vector<int>& candidates, int target) {
        if (sum == target) {
            results.push_back(result);
            return;
        } 

        if (sum > target) {
            return;
        }

        for (int i = lastIndex; i < candidates.size(); ++i) {
            int candidate = candidates[i];
            result.push_back(candidate);
            dfs(result, sum + candidate, i, candidates, target);
            result.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> result;
        dfs(result, 0, 0, candidates, target);
        return results;
    }
};