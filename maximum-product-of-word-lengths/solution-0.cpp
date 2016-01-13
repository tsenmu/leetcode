class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> reps(n, 0);
        for (int i = 0; i < n; ++i) {
            int mask = 0;
            for (int j = 0; j < words[i].length(); ++j) {
                mask |= (1 << int(words[i][j] - 'a'));
            }
            reps[i] = mask;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (!(reps[i] & reps[j])) {
                    ans = max((int)(words[i].length() * words[j].length()), ans);
                }
            }
        }

        return ans;
    }
};