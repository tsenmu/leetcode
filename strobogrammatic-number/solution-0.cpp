class Solution {
private:
    unordered_map<int, int> m_reversedDigit;

    void initializeReversedDigits() {
        m_reversedDigit[0] = 0;
        m_reversedDigit[1] = 1;
        m_reversedDigit[2] = -1;
        m_reversedDigit[3] = -1;
        m_reversedDigit[4] = -1;
        m_reversedDigit[5] = -1;
        m_reversedDigit[6] = 9;
        m_reversedDigit[7] = -1;
        m_reversedDigit[8] = 8;
        m_reversedDigit[9] = 6;
    }
public:
    Solution() {
        initializeReversedDigits();
    }

    bool isStrobogrammatic(string num) {
        const int len = (int) num.length();
        string reversedNum = num;
        for (int i = 0; i < len; ++i) {
            int reversedDigit = m_reversedDigit[num[i] - '0'];
            reversedNum[len - i - 1] = reversedDigit + '0';
        }
        return reversedNum == num;
    }
};