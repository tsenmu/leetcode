class Solution {
public:
    string reverseVowels(string s) {
        if (s.length() == 0) {
            return s;
        }
        
        set<char> S;
        S.insert('a');
        S.insert('e');
        S.insert('i');
        S.insert('o');
        S.insert('u');

        int l = 0; 
        int r = s.length() - 1;
        while (l < r) {
            if (!S.count(tolower(s[l]))) {
                l++;
            } else if (!S.count(tolower(s[r]))) {
                r--;
            } else {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};