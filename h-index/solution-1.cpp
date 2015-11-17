class Solution {
public:
  int hIndex(vector<int>& citations) {
    const int n = citations.size();
    int count[n + 1]; // count[i] is the number of papers that has i citations.
    memset(count, 0, sizeof count);

    for (int i = 0; i < n; ++i) {
      count[citations[i] > n ? n : citations[i]]++;
    }

    int sum = 0;
    for (int i = n; i >= 0; --i) {
      sum += count[i]; // sum is the number of papers that has more than i citations
      if (sum >= i) {
        return i;
      }
    }
  }
};