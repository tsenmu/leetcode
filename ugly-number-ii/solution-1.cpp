class Solution {
public:
  int nthUglyNumber(int n) {
    int indices[] = {0, 0, 0};
    int primes[] = {2, 3, 5};
    int uglyNumbers[n];
    uglyNumbers[0] = 1;

    for (int i = 1; i < n; ++i) {
      int minVal = INT_MAX;
      for (int j = 0; j < 3; ++j) {
        minVal = min(minVal, uglyNumbers[indices[j]] * primes[j]); 
      }
      uglyNumbers[i] = minVal;
      for (int j = 0; j < 3; ++j) {
        if (uglyNumbers[indices[j]] * primes[j] == minVal) {
          indices[j]++;
        } 
      }
    }
    return uglyNumbers[n - 1];
  }
};