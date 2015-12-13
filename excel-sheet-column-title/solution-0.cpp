class Solution {
public:
    string convertToTitle(int n) {
        if (n <= 0) {
            return "";
        }       

        string ans;

        while (n > 0) {
            ans += (char)( (n - 1) % 26) + 'A';
            n = (n - 1) / 26;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};