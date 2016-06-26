class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1; 
        }

        if (n == 1) {
            return 10;
        }

        if (n > 10) {
            return countNumbersWithUniqueDigits(10);
        }

        int ans = 9;
        int remainingDigits = 9;
        for (int i = 0; i < n - 1; ++i) {
            ans *= remainingDigits;
            remainingDigits--;
        }
        ans += countNumbersWithUniqueDigits(n - 1);

        return ans;
    }
};