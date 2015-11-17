class Solution {
public:
  int nthUglyNumber(int n) {
    int primeFactors[3] = {2, 3, 5};

    long long uglyNumbers[n];
    uglyNumbers[0] = 1; 

    for (int i = 1; i < n; ++i) {
      int minVal = INT_MAX;
      for (int j = 0; j < 3; ++j) {
        for (int k = i - 1; k >= 0; --k) {
          long long val = uglyNumbers[k] * primeFactors[j];
          if (val <= uglyNumbers[i - 1]) {
            break;
          }
          if (val < minVal) {
            minVal = val;
          }
        }
      }
      uglyNumbers[i] = minVal;
    }
    return uglyNumbers[n - 1];
  }
};