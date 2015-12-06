class Solution {
public:
    vector<vector<int>> results;

    void dfs(vector<int>& result, int sum, int lastIndex, vector<int>& candidates, int target, int size) {
        if (sum == target && size == result.size()) {
            results.push_back(result);
            return;
        } 

        if (result.size() > size) {
            return;
        }

        if (sum > target) {
            return;
        }

        for (int i = lastIndex + 1; i < candidates.size(); ++i) {
            int candidate = candidates[i];

            if (i > lastIndex + 1 && candidates[i] == candidates[i - 1]) {
                continue;
            }
            result.push_back(candidate);
            dfs(result, sum + candidate, i, candidates, target, size);
            result.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates;
        for (int i = 1; i <= 9; ++i) {
            candidates.push_back(i);
        }
        vector<int> result;
        dfs(result, 0, -1, candidates, n, k);
        return results;
    }
};