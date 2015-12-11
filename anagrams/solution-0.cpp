class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> stats(strs.size(), vector<int>(26, 0));

        map<string, vector<int> > M;
        for (int i = 0; i < strs.size(); ++i) {
            for (int j = 0; j < strs[i].length(); ++j) {
                stats[i][(strs[i][j] - 'a')]++;
            }
            ostringstream oss;
            for (int j = 0; j < 26; ++j) {
               oss << stats[i][j] << ",";
            }
            M[oss.str()].push_back(i);
        }

        vector<vector<string>> ans;
        for (auto it = M.begin(); it != M.end(); ++it) {
            vector<int> & list = it->second;
            vector<string> par_ans;
            for (int i = 0; i < list.size(); ++i) {
                par_ans.push_back(strs[list[i]]);
            }

            sort(par_ans.begin(), par_ans.end());
            ans.push_back(par_ans);
        }

        return ans;
    }
};