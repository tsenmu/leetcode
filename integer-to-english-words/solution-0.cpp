class Solution {

public:
    string numberToWords(int num) {
        generateNumberEnglishMapping();

        if (num == 0) {
            return m_numbers[0];
        }

        int magnitude = 1;
        vector<string> tokens;
        while (num) {
            int currentNum = num % 1000;
            vector<string> threeDigitTokens = processThreeDigits(currentNum, magnitude);
            for (int i = 0; i < tokens.size(); ++i) {
                threeDigitTokens.push_back(tokens[i]);
            }
            tokens = threeDigitTokens;
            magnitude *= 1000;
            num /= 1000;
        }
        string ans;
        for (int i = 0; i < tokens.size(); ++i) {
            if (i == tokens.size() - 1) {
                ans += tokens[i];
            } else {
                ans += tokens[i] + " ";
            }
        }
        return ans;
    }

protected: 
    unordered_map<int, string> m_numbers;

    vector<string> processThreeDigits(int num, int magnitude) {
        vector<string> tokens;

        if (num == 0) {
            return tokens;
        }

        int hundredDigit = num / 100;
        int tenDigit = (num / 10) % 10;
        int oneDigit = num % 10;

        if (hundredDigit) {
            tokens.push_back(m_numbers[hundredDigit]);
            tokens.push_back(m_numbers[100]);
        }

        if (tenDigit == 1) {
            tokens.push_back(m_numbers[tenDigit * 10 + oneDigit]);
        } else if (tenDigit == 0) {
            if (oneDigit != 0) {
                tokens.push_back(m_numbers[oneDigit]);
            }
        } else {
            tokens.push_back(m_numbers[tenDigit * 10]);
            if (oneDigit != 0) {
                tokens.push_back(m_numbers[oneDigit]);
            }
        }

        if (magnitude != 1) {
            tokens.push_back(m_numbers[magnitude]);
        }

        return tokens;
    }

    void generateNumberEnglishMapping() {
        unordered_map<int, string>& numbers = m_numbers;
        if (numbers.size() == 0) {
            numbers[0] = "Zero";
            numbers[1] = "One";
            numbers[2] = "Two";
            numbers[3] = "Three";
            numbers[4] = "Four";
            numbers[5] = "Five";
            numbers[6] = "Six";
            numbers[7] = "Seven";
            numbers[8] = "Eight";
            numbers[9] = "Nine";
            numbers[10] = "Ten";
            numbers[11] = "Eleven";
            numbers[12] = "Twelve";
            numbers[13] = "Thirteen";
            numbers[14] = "Fourteen";
            numbers[15] = "Fifteen";
            numbers[16] = "Sixteen";
            numbers[17] = "Seventeen";
            numbers[18] = "Eighteen";
            numbers[19] = "Nineteen";
            numbers[20] = "Twenty";
            numbers[30] = "Thirty";
            numbers[40] = "Forty";
            numbers[50] = "Fifty";
            numbers[60] = "Sixty";
            numbers[70] = "Seventy";
            numbers[80] = "Eighty";
            numbers[90] = "Ninety";
            numbers[100] = "Hundred";
            numbers[1e3] = "Thousand";
            numbers[1e6] = "Million";
            numbers[1e9] = "Billion";
            numbers[1e12] = "Trillion"; 
        }
    }
};