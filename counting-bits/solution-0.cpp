class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;

        result.push_back(0);
        if (num == 0) {
            return result;
        }

        result.push_back(1);
        if (num == 1) {
            return result;
        }

        int powerOfTwo = 2;

        for (int i = 2; i <= num; ++i) {
            if (i == powerOfTwo) {
                result.push_back(1);
                powerOfTwo <<= 1;
            } else {
                result.push_back(result[i - (powerOfTwo >> 1)] + 1);
            }
        }
        return result;
    }
};



// 16 -> 10000 1

// 15 -> 01111 4
// 14 -> 01110 3
// 13 -> 01101 3
// 12 -> 01100 2

// 11 -> 01011 3
// 10 -> 01010 2
// 9  -> 01001 2
// 8  -> 01000 1

// 7  -> 00111 3
// 6  -> 00110 2
// 5  -> 00101 2
// 4  -> 00100 1

// 3  -> 00011 2
// 2  -> 00010 1
// 1  -> 00001 1
// 0  -> 00000 0