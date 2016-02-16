class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        if (n == m) {
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] != t[i]) {
                    count++;
                }
            }
            return count == 1;
        } else if (n == m + 1) {
            // n > m
            if (m == 0) {
                return true;
            }

            int i = 0, j = 0;
            int count = 0;
            
            //ba
            //a
            while (i < n && j < m) {
                 if (s[i] != t[j]) {
                    count++;
                    i++;
                 } else {
                     j++;
                     i++;
                 }
            }
            return count == 1 || i == j;
        } else if (n + 1 == m) {
            return isOneEditDistance(t, s);
        } else {
            return false;
        }
    }
};