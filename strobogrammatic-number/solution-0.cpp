class Solution {
protected:
    unordered_map<int, int> m_map;
    void createDigitMap() {
        m_map[0] = 0; 
        m_map[1] = 1;
        m_map[2] = -1;
        m_map[3] = -1;
        m_map[4] = -1;
        m_map[5] = -1;
        m_map[6] = 9;
        m_map[7] = -1;
        m_map[8] = 8;
        m_map[9] = 6;
    }
    bool calculateRotated(const string& str, string& ans) {
        const int n = str.length();
        ans.clear();
        for (int i = 0; i < n; ++i) {
            int digit = (int)(str[i] - '0');
            if (m_map[digit] == -1) {
                return false;
            }
            ans.push_back((char)(m_map[digit] + '0'));
        }
        reverse(ans.begin(), ans.end());
        return true;
    }  
public:
    bool isStrobogrammatic(string num) {
        if (m_map.size() == 0) {
            createDigitMap();
        }
        string stro;
        if (!calculateRotated(num, stro)) {
            return false; 
        }
        cout << stro << endl;
        return num == stro;
    }
};