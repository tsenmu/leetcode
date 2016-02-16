class Solution {
protected:
    unordered_map<string, bool> M;
public:
    bool canWin(string s) {
        if (M.count(s) == 1) {
            return M[s];
        }
        vector<string> nexts;
        for (int i = 1; i < s.length(); ++i) {
            string next = s;
            if (s[i] == '+' && s[i - 1] == '+') {
                next[i] = '-'; 
                next[i - 1] = '-';
                nexts.push_back(next);
            }
        }

        if (nexts.empty()) {
            return M[s] = false;
        }

        for (int i = 0; i < nexts.size(); ++i) {
            if (!canWin(nexts[i])) {
                return M[s] = true;
            } 
        }
        return M[s] = false;
    }
};