class Solution {
protected:
    unordered_map<int, int> m_map;
    vector<int> m_sym;

    string rotate(const string& str) {
        string ans;
        const int n = str.length();
        for (int i = n - 1; i >= 0; --i) {
            ans += to_string(m_map[str[i] - '0']);
        }
        cout << str << " " << ans << endl;
        return ans;
    }
    void dfs(
        vector<string>& ans, 
        string& res,
        int index,
        const int n
        ) {
        if (index == (n >> 1)) {
            string res_rot = rotate(res);
            if (n & 1) {
                for (int i = 0; i < m_sym.size(); ++i) {
                    ans.push_back(res + to_string(m_sym[i]) + res_rot);
                }
            } else {
                ans.push_back(res + res_rot);
            }
            return;
        }

        for (auto it = m_map.begin(); it != m_map.end(); ++it) {
            if (it->first == 0 && index == 0) {
                continue;
            }
            res.push_back('0' + it->first);
            dfs(ans, res, index + 1, n);
            res.pop_back();
        }
    }

    void constructMaps() {
        if (m_map.empty()) {
            m_map[0] = 0;
            m_map[1] = 1;
            m_map[6] = 9;
            m_map[8] = 8;
            m_map[9] = 6;
        }

        if (m_sym.empty()) {
            m_sym.push_back(0);
            m_sym.push_back(1);
            m_sym.push_back(8);
        }
    }
public:
    vector<string> findStrobogrammatic(int n) {
        constructMaps();
        vector<string> ans;
        string res;
        dfs(ans, res, 0, n);
        return ans;
    }
};