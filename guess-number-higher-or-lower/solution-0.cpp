// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;       
        int r = n;
        int m;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            int g = guess(m);
            if (g > 0) {
                l = m + 1;
            } else if (g < 0) {
                r = m - 1;
            } else {
                break;
            }
        }
        return m;
    }
};