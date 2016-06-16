class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int n = nums.size();


        vector<int> result;
        unordered_map<int, int> frequency;
        vector<vector<int>> bucket(n + 1, vector<int>());

        for (int i = 0; i < n; ++i) {
            frequency[nums[i]]++;
        }

        for (auto it = frequency.begin(); it != frequency.end(); ++it) {
            bucket[it->second].push_back(it->first);
        }

        for (int i = n; i >= 0; --i) {
            if (!bucket[i].empty()) {
                for (int j = 0; j < bucket[i].size(); ++j) {
                    result.push_back(bucket[i][j]);
                    k--;
                    if (k == 0) {
                        break;
                    }
                }
                if (k == 0) {
                    break;
                }
            }
        }

        return result;
    }
};