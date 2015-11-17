#include <cstdio>

class Solution {
public:
  int countPrimes(int n) {
    int ans = 0;

    bool is_prime[n];

    for (int i = 0; i < n; ++i) {
      is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < n; ++i) {
      if (is_prime[i]) {
        ans++;
        for (int j = 2; j * i < n; ++j) {
          is_prime[j * i] = false;
        }
      }
    }

    return ans;
  }
};


int main() {
  Solution sol;
  printf("%d\n", sol.countPrimes(1500000));
  return 0;
}