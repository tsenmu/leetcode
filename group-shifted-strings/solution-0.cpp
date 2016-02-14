class Solution {
protected:
    string calculateEncodedString(const string& str) {
        const int n = str.length();
        string ans;
        for (int i = 1; i < n; ++i) {
            int last = (int)str[i - 1];
            int current = (int)str[i];
            int diff = 0;
            if (current >= last) {
                diff = current - last;
            } else {
                diff = 26 - (last - current);
            }
            ans += (char)('a' + diff);
        }
        return ans;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<int>> M;       
        const int n = strings.size();
        for (int i = 0; i < n; ++i) {
            string encoded = calculateEncodedString(strings[i]);
            M[encoded].push_back(i);
        }

        vector<vector<string>> ans;

        for (auto it = M.begin(); it != M.end(); ++it) {
            vector<string> seq;
            const vector<int>& indices = it->second;
            for (int i = 0; i < indices.size(); ++i) {
                seq.push_back(strings[indices[i]]);
            }
            sort(seq.begin(), seq.end());
            ans.push_back(seq);
        }
        return ans;
   }
};