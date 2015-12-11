class Solution {
public:
    int len(int pos, bool fore, string& s) {
        int l, r;
        int ans = 0;
        l = pos - 1;
        r = pos;
        if (!fore) {
            r++;
        } 
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
            ans++;
        }
        return ans;
    }

    string longestPalindrome(string s) {
        if (s.empty()) {
            return s;
        }

        int maxi = 0;
        bool maxfore = false; 
        int maxv = 0;
        for (int i = 0; i < s.length(); ++i) {
            int val = len(i, true, s);
            if (val > maxv) {
                maxi = i;
                maxv = val;
                maxfore = true;
            }
            val = len(i, false, s);
            if (val + 1 > maxv) {
                maxi = i;
                maxv = val;
                maxfore = false;
            }
        }
        if (maxfore) {
            return s.substr(maxi - maxv, maxv << 1);
        } else {
            return s.substr(maxi - maxv, (maxv << 1) + 1);
        }
    }
};