class Solution {
protected:
    unordered_map<string, bool> M;
public:
    bool canWin(string s) {
        if (M.count(s) == 1) {
            return M[s];
        }
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == '+' && s[i - 1] == '+') {
                string left = s.substr(0, i - 1);
                string right = s.substr(i + 1);
                if (!canWin(left) && !canWin(right)) {
                    return M[s] = true;
                }
            }
        }

        return M[s] = false;
    }
};