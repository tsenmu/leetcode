class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        const int n = nums.size();

        if (n == 0) {
            return 0;
        }

        unordered_map<int, pair<int, int>> L;
        unordered_map<int, pair<int, int>> R;
        unordered_set<int> S;

        for (int i = 0; i < n; ++i) {
            const int& val = nums[i];
            if (!S.count(val)) {

                bool leftFound = L.count(val + 1) != 0;
                bool rightFound = R.count(val - 1) != 0;
                if (leftFound && rightFound) {
                    L[R[val - 1].first] = make_pair(R[val - 1].first, L[val + 1].second);
                    R[L[val + 1].second] = make_pair(R[val - 1].first, L[val + 1].second);
                    L.erase(val + 1);
                    R.erase(val - 1);
                } else if (leftFound) {
                    L[val] = make_pair(val, L[val + 1].second);
                    R[L[val + 1].second] = make_pair(val, L[val + 1].second);
                    L.erase(val + 1);
                } else if (rightFound) {
                    R[val] = make_pair(R[val - 1].first, val);
                    L[R[val - 1].first] = make_pair(R[val - 1].first, val);
                    R.erase(val - 1);
                } else {
                    L[val] = make_pair(val, val);
                    R[val] = make_pair(val, val);
               }

                S.insert(val);
            } 

            // for (auto it = L.begin(); it != L.end(); ++it) {
            //     printf("<%d,%d> ", it->second.first, it->second.second);
            // }
            // printf("\n");

            // for (auto it = R.begin(); it != R.end(); ++it) {
            //     printf("<%d,%d> ", it->second.first, it->second.second);
            // }
            // printf("\n\n");

        }

        int ans = 0;
        for (auto it = L.begin(); it != L.end(); ++it) {
            ans = max(ans, it->second.second - it->second.first + 1);
        }

        return ans;
    }
};