class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        const int n = S.length();       

        string ans;
        int current_section_chars = 0;
        for (int i = n - 1; i >= 0; --i) {
            const char ch = toupper(S[i]);
            if (ch != '-') {
                current_section_chars++;
                ans.push_back(ch);
                if (current_section_chars == K) {
                    current_section_chars = 0;
                    ans.push_back('-');
                }
            }
        }
        if (!ans.empty() && ans[ans.size() - 1] == '-') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};