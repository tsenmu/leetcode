class Solution {
private: 
  unordered_map<int, int> m_cache; 
public:
  int numTrees(int n) {
    if (m_cache.count(n)) {
      return m_cache[n];
    }
    if (n == 0) {
      return m_cache[n] = 1;
    }
    if (n == 1) {
      return m_cache[n] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
       ans += numTrees(i) * numTrees(n - i - 1);
    }
    return m_cache[n] = ans;
  }
};