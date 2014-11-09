class Solution {
public:
    void reverseWords(string &s) {
      istringstream iss(s);
      string token;
      string result;
      while(iss >> token) {
        result = token + " " + result;
      }
      s = result.substr(0, result.length() - 1);
    }
};
