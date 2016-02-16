class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;       
        const int n = s.length();
        for (int i = 1; i < n; ++i) {
            string next = s;
            if (s[i] == '+' && s[i - 1] == '+') {
                next[i] = '-';
                next[i - 1] = '-';
                ans.push_back(next);
            }
        }
        return ans;
    }
};