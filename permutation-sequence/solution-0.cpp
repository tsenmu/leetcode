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
    memset(visited, false, sizeof visited);
    int m = n - 1;
    k -= 1;
    while (m) {
      int round = k / factors[m];
      k -=  round * factors[m];
      for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
          if (round == 0) {
            visited[i] = true;
            ans.push_back('0' + i);
          }
          round--;
        }
      }
      m--;
    }
    for (int i = 1; i <= n; ++i) {
      if (!visited[i]) {
        ans.push_back('0' + i);
      }
    }
    return ans;
  }
};