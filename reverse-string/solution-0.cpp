class Solution {
public:
    string reverseString(string s) {
        if (s.length() == 0) {
            return s;
        }

        for (int i = 0; i < (s.length() >> 1); ++i) {
            swap(s[i], s[s.length() - i - 1]);
        }

        return s;
    }
};