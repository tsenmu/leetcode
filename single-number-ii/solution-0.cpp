class Solution {
public:
    int singleNumber(int A[], int n) {
      map<int, int> M;
      for (int i = 0; i < n; ++i) {
        M[A[i]]++;
      }
      map<int, int>::iterator it;
      for(it = M.begin(); it != M.end(); ++it) {
        if (it->second == 1) {
          return it->first;
        }
      }
    }
};
