class Solution {
public:
    string removeDuplicateLetters(string s) {
        const int n = s.length();
        vector<int> count(26, 0);
        vector<bool> visited(26, false);
        for (int i = 0; i < n; ++i)  {
            count[s[i] - 'a']++;
        }

        string ans;

        for (int i = 0; i < n; ++i) {
            if (visited[s[i] - 'a']) {
                count[s[i] - 'a']--;
                continue;
            }

            while (!ans.empty()) {
                char top = ans.back();
                if (top > s[i] && count[top - 'a'] > 0) {
                    ans.pop_back();
                    visited[top - 'a'] = false;
                } else {
                    break;
                }
            }
            ans.push_back(s[i]);
            count[s[i] - 'a']--;
            visited[s[i] - 'a'] = true;
        }


        return ans;
    }
};