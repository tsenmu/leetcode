class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        const int k = primes.size();
        vector<int> uglyNumbers(n, 0);
        vector<int> indices(k, 0);
        uglyNumbers[0] = 1;
    
        for (int i = 1; i < n; ++i) {
          int minVal = INT_MAX;
          for (int j = 0; j < k; ++j) {
            minVal = min(minVal, uglyNumbers[indices[j]] * primes[j]); 
          }
          uglyNumbers[i] = minVal;
          for (int j = 0; j < k; ++j) {
            if (uglyNumbers[indices[j]] * primes[j] == minVal) {
              indices[j]++;
            } 
          }
        }
        return uglyNumbers[n - 1];
    }
};