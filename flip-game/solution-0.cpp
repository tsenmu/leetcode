class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        int len = (int) s.length();
        for (int i = 0; i < len - 1; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                result.push_back(s);
                result[result.size() - 1][i] = '-';
                result[result.size() - 1][i + 1] = '-';
            }
        }
        return result;
    }
};