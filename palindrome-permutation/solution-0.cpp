class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> count;
        for (int i = 0; i < s.length(); ++i) {
            count[s[i]]++;
        }
        int oddCount = 0;
        for (auto it = count.begin(); it != count.end(); ++it) {
            if (it->second & 1) {
                oddCount++;
            } 
        }

        if (s.length() & 1) {
            if (oddCount == 0 || oddCount == 1) {
                return true;
            }
        } else {
            if (oddCount == 0) {
                return true;
            }
        }
        return false;
    }
};