class Solution {
public:
  string countAndSay(int n) {
    string ans = "1";
    while (--n) {
      string temp;
      char ch = 0;
      int count = 0;
      for (int i = 0; i < ans.length(); ++i) {
        if (count == 0) {
          ch = ans[i];
          count++;
        } else {
          if (ch == ans[i]) {
            count++;
          } else {
            ostringstream oss;
            oss << count << ch;
            temp += oss.str();
            
            ch = ans[i];
            count = 1;
          }
        }
      }
      if (count > 0) {
        ostringstream oss;
        oss << count << ch;
        temp += oss.str();
      }
      ans  = temp;
    }
    return ans;
  }
};