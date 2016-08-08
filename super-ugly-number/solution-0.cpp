class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();

        if (k == 0) {
          return 1;
        }

        vector<int> uglyNumbers(n, 0);
        vector<int> nextCandidates(k, 0);
        uglyNumbers[0] = 1;

        for (int i = 1; i < n; ++i) {
          int uglyNumber = INT_MAX;
          int primeIndex = -1;
          for (int j = 0; j < k; ++j) {
            int candidate = uglyNumbers[nextCandidates[j]] * primes[j];
            if (candidate < uglyNumber) {
              uglyNumber = candidate;
              primeIndex = j;
            }
          }
          uglyNumbers[i] = uglyNumber;
          nextCandidates[primeIndex]++;
        }

        return uglyNumbers[n - 1];
    }
};