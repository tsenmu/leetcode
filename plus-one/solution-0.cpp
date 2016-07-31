class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;       

        // Deal with corner case.
        if (digits.empty()) {
          result.push_back(1);
          return result;
        }

        // Plus one.
        int carry = 1;
        int sum = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
          sum = digits[i] + carry;
          result.push_back(sum % 10);
          carry = sum / 10;
        }

        // Deal with remaining carry;
        if (carry) {
          result.push_back(carry);
        }

        // Reverse the result. 
        reverse(result.begin(), result.end());
        return result;
    }
};