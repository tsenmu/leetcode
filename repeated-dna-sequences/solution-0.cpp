class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int running_mask = 0;
        unordered_map<int, int> M;
        unordered_map<int, int> pos;
        for (int i = 0; i < s.length(); ++i) {
            running_mask <<= 2;
            switch (s[i]) {
            case 'A': break; 
            case 'C': running_mask |= 1; break;
            case 'G': running_mask |= 2; break;
            case 'T': running_mask |= 3; break;
            }
            running_mask &= ((1 << 20) - 1);
            if (i >= 9) {
                M[running_mask]++;
                pos[running_mask] = i - 9;
            }
        }
        vector<string> ans;
        for (auto it = M.begin(); it != M.end(); ++it) {
            if (it->second > 1) {
                ans.push_back(s.substr(pos[it->first], 10));
            } 
        }
        return ans;
    }
};