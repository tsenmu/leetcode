class Solution {
protected:
    int charToDigit(char ch) {
        if (ch == 'X') {
            return 0;
        }
        return (int) (ch - '0');
    }

    bool isValid(const string& s) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '0') {
                if (i == 0) {
                    return false; 
                } else {
                    if (s[i - 1] != '1' && s[i - 1] != '2') {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    string convertOffTenMultiples(const string& s) {
        const int n = s.length();
        string ans; 
        bool lastIsTenMultiple = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') {
                    ans.pop_back();
                    ans += 'X';
                } 
            } else {
                ans += s[i];
            }
        }

        return ans;
    }

public:
    int numDecodings(string s) {
        int n = s.length();

        if (n == 0) {
            return 0;
        } else if (n == 1) {
            if (s[0] == '0') {
                return 0;
            } else {
                return 1;
            }
        }

        if (!isValid(s)) {
            return 0;
        }

        s = convertOffTenMultiples(s);
        cout << s << endl;
        n = s.length();

        // now n >= 2

        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        int runningNumber = charToDigit(s[0]);

        for (int i = 1; i < n; ++i) {
            int digit = charToDigit(s[i]);

            runningNumber = (runningNumber % 10) * 10 + digit;

            if (runningNumber != 10 && runningNumber != 20 && 
                runningNumber >= 10 && runningNumber <= 26) {
                dp[i + 1] += dp[i - 1];
            }
            dp[i + 1] += dp[i];
        }
        
        for (int i = 0; i <= n; ++i) {
            printf("%d ", dp[i]);
        }
        printf("\n");

        return dp[n];
    }
};