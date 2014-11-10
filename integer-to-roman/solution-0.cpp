class Solution {
public:
    string intToRoman(int num) {
      string ans;
      int digit = 0;
      map< pair<int, int>, string> M;
      M[make_pair(0, 1)] = 'I';
      M[make_pair(0, 5)] = 'V';
      M[make_pair(1, 1)] = 'X';
      M[make_pair(1, 5)] = 'L';
      M[make_pair(2, 1)] = 'C';
      M[make_pair(2, 5)] = 'D';
      M[make_pair(3, 1)] = 'M';
      while(num) {
        string prepend;
        int v = num % 10;
        if (v >= 1 && v <= 3) {
          for (int i = 0; i < v; ++i) {
            prepend += M[make_pair(digit, 1)];
          }
        } else if (v >= 4 && v <= 8) {
          for (int i = 0; i < 5 - v; ++i) {
            prepend += M[make_pair(digit, 1)];
          }
          prepend += M[make_pair(digit, 5)];
          for (int i = 0; i < v - 5; ++i) {
            prepend += M[make_pair(digit, 1)];
          }
        } else if (v == 9) {
          prepend += M[make_pair(digit, 1)] + M[make_pair(digit + 1, 1)];
        }
        ans = prepend + ans;
        num /= 10;
        digit++;
      }
      return ans;
    }
};
