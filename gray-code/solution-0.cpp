class Solution {
public:
    vector<int> grayCode(int n) {
        const int total = 1 << n;
        vector<int> result(total, 0);

        int digit = 0;
        for (int i = 1; i < total; ++i) {
            result[i] = (1 << digit) | result[(1 << (digit + 1)) - i - 1];
            if (i + 1 == (1 << (digit + 1))) {
                digit++;
            }
        }

        return result; 
    }
};