class Solution {
public:
  string getPermutation(int n, int k) {
    int factors[n + 1];      
    factors[1] = 1;
    for (int i = 2; i <= n; ++i) {
      factors[i] = factors[i - 1] * i;
    }

    string ans;
    bool visited[n + 1];
    int m = n - 1;
    int start = 0;
    k -= 1;
    while (m) {
      int round = k / factors[m];
      k -=  round * factors[m];
      ans.push_back(start + round + '0');
      start++;
      m--;
    }
    for (int i = start; i <= n; ++i) {
      ans.push_back('0' + i);
    }
    return ans;
  }
};