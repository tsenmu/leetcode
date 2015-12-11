class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        vector<string> buf(numRows, string(s.length(), '\0'));
        
        int direction = 0; 
        int x = 0;
        int y = 0;

        int max_x = 0;

        for (int i = 0; i < s.length(); ++i) {
            max_x = max(x, max_x);
            buf[y][x] = s[i];

            switch (direction) {
            case 0:
                if (y == numRows - 1) {
                    y--; 
                    x++;
                    direction = 1;
                } else {
                    y++;
                }
                break;
            case 1:
                if (y == 0) {
                    y++;
                    direction = 0;
                } else {
                    y--;
                    x++;
                }
                break;
            }
        }

        string ans;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < 1 + max_x; ++j) {
                if (buf[i][j] != '\0') {
                    ans += buf[i][j];
                }
            } 
        }

        return ans;
    }
};