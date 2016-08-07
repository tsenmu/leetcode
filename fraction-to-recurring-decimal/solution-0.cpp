class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        bool isNegative = false;
        if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) {
            isNegative = true;
        } 

        numerator = abs(numerator);
        denominator = abs(denominator);
        
        long long integerPart = numerator / denominator;

        long long remain = numerator % denominator;
        if (remain == 0) {
            if (isNegative) {
                return "-" + to_string(integerPart);
            } else {
                return to_string(integerPart);
            }
        }

        vector<int> digits;
        unordered_map<int, int> M;
        int repeatStart = -1;
        while (remain != 0) {
            remain *= 10;
            if (M.count(remain) == 1) {
                repeatStart = M[remain];
                break;
            }
            digits.push_back(remain / denominator);
            M[remain] = digits.size() - 1;
            remain %= denominator;
        }

        string ans = to_string(integerPart) + ".";

        if (repeatStart == -1) {
            for (int digit : digits) {
                ans += to_string(digit);
            }
        } else {
            for (int i = 0; i < repeatStart; ++i) {
                ans += to_string(digits[i]);
            }
            ans += "(";
            for (int i = repeatStart; i < digits.size(); ++i) {
                ans += to_string(digits[i]);
            }
            ans += ")";
        }

        if (isNegative) {
            ans = "-" + ans;
        } 
        return ans; 
    }
    string fractionToDecimal(int numerator, int denominator) {
        return fractionToDecimal((long long)numerator, (long long)denominator);
    }
};