class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        unordered_map<int, int> M;
        ostringstream oss;

        long long num = numerator;
        long long den = denominator;

        int negCount = 0;

        if (num < 0) {
            negCount++;
            num = -num; 
        }

        if (den < 0) {
            negCount++;
            den = -den;
        }

        long long dec = num / den;
        num %= den;

        if (!(dec == 0 && num == 0)) {
            if (negCount & 1) {
                oss << "-";
            }
        }

        oss << dec;
        
        if (num == 0) {
            return oss.str();
        } 
        
        oss << ".";

        vector<int> digits;

        num *= 10;

        int repeatFrom = -1;

        while (true) {
            if (M.count(num) == 1) {
                repeatFrom = M[num];
                break;
            }
            M[num] = (int) digits.size();
            
            if (num < den) {
                digits.push_back(0);
                num *= 10;
            } else {
                long long mul = num / den; 
                long long rem = num - mul * den;
                digits.push_back(mul);

                if (rem == 0) {
                    break;
                }
                
                num = rem * 10;
            }
        }

        if (repeatFrom != -1) {
            for (int i = 0; i < repeatFrom; ++i) {
                oss << digits[i];
            }
            oss << '(';
            for (int i = repeatFrom; i < digits.size(); ++i) {
                oss << digits[i];
            }
            oss << ')';
        } else {
            for (int i = 0; i < digits.size(); ++i)  {
                oss << digits[i];
            }
        }

        return oss.str();
    }
};