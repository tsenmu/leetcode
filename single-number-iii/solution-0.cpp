class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    // Get the XOR of the two single number.
    int singleNumbersXor = 0;
    for (int i = 0; i < nums.size(); ++i) {
      singleNumbersXor ^= nums[i]; 
    }

    // The two single number must have some bit different, 
    // find the first occurrence of difference.
    int bitFirstDifferentAt = 0; 
    for (int i = 0; i < 32; ++i) {
      if (singleNumbersXor & (1 << i)) {
        bitFirstDifferentAt = i;
        break;
      }
    }

    // Numbers other than the two single numbers may be classified
    // into two sets according to the 1 and 0 of this certain bit
    // we found.
    // XOR of the first set results in the first number;
    // XOR of the second set results in the second number.
    int firstNumber = 0;
    int secondNumber = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] & (1 << bitFirstDifferentAt)) {
        firstNumber ^= nums[i];
      } else {
        secondNumber ^= nums[i];
      }
    }

    // Answer.
    vector<int> ans;
    ans.push_back(firstNumber);
    ans.push_back(secondNumber);
    return ans;
  }
};