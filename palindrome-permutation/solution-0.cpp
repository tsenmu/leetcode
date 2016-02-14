class Solution {
public:
    bool canPermutePalindrome(string s) {
        const int n = s.length();

        const int max_char = 255;

        vector<int> count(max_char, 0);

        for (int i = 0; i < n; ++i) {
            count[(int)s[i]]++;
        }

        int oddCount = 0;
        int evenCount = 0;
        for (int i = 0; i < max_char; ++i) {
            if (count[i]) {
                if (count[i] & 1) {
                    oddCount++;
                } else {
                    evenCount++;
                }
            }
        }

        if (n & 1) {
            return oddCount == 1;
        } else {
            return oddCount == 0;
        }
    }
};