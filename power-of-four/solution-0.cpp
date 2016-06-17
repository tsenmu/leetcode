class Solution {
public:
    bool isPowerOfFour(int num) {
        int count = 0;
        int pos = 0;
        if (num < 0) {
            return false;
        }
        for (int i = 0; i < 31; ++i) {
            if (num & (1 << i)) {
                count++;
                pos = i;
            }
            if (count == 2) {
                return false;
            }
        }
        
        if (count == 1 && !(pos & 1)) {
            return true;
        }
        return false;
    }
};
