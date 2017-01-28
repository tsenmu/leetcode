class Solution {
public:
    bool isStrobogrammatic(string num) {
        const int num_len = num.length();
        for (int i = 0; i < num_len; ++i) {
            if (strobogrammatic_number_map_[CharToInt(num[i])] 
                != CharToInt(num[num_len - i - 1])) {
                return false;
            }
        }
        return true;
    }
private: 
    int CharToInt(char ch) {
        return static_cast<int>(ch - '0');
    }
    unordered_map<int, int> strobogrammatic_number_map_ = {
        {0, 0},
        {1, 1},
        {2, -1},
        {3, -1},
        {4, -1},
        {5, -1},
        {6, 9},
        {7, -1},
        {8, 8},
        {9, 6}
    };
};