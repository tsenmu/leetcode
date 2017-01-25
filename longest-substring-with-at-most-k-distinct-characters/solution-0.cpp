class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        const int n = s.length();

        if (n == 0 || k == 0) {
            return 0;
        }

        int ans = 1;
        unordered_map<char, int> active_chars;       
        active_chars[s[0]] = 1;

        int l = 0;
        for (int r = 1; r < n; ++r) {
            const char ch = s[r];
            active_chars[ch]++;
            while (active_chars.size() > k) {
                active_chars[s[l]]--;
                if (active_chars[s[l]] == 0) {
                    active_chars.erase(s[l]);
                }
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};