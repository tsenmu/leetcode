class Solution {
public:
    string trim(string s) {
        int start = -1;
        int end = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (!isspace(s[i])) {
                start = i;
                break;
            }
        }

        for (int i = s.length() - 1; i >= 0; --i) {
            if (!isspace(s[i])) {
                end = i;
                break;
            }
        }

        if (start == -1 || end == -1) {
            return "";
        } else {
            return s.substr(start, end - start + 1);
        }
    }
    bool isNumber(string s) {
        s = trim(s);

        if (s.length() == 0) {
            return false;
        }

        int dotCount = 0;
        int eCount = 0;
        int plusCount = 0;
        int minusCount = 0;
        int digitCount = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])) {
                
            } else if (isspace(s[i])) {
                return false;
            } else if (s[i] == '.') {
                if (dotCount) {
                    return false;
                }
                dotCount++;
            } else if (s[i] == 'e') {

            } else if (s[i] == '+') {

            } else if (s[i] == '-') {

            }
        }
    }
};