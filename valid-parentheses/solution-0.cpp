class Solution {
public:
  bool isValid(string s) {
    stack<char> S;      
    for (int i = 0; i < s.size(); ++i) {
      char ch = s[i];
      if (ch == ')' || ch == '}' || ch == ']') {
        if (!S.empty()) {
          char top = S.top();
          if (top == '(' && ch == ')' || top == '{' && ch == '}' || top == '[' && ch == ']') {
            S.pop();
          } else {
              return false;
          }
        } else {
          return false;
        }
      } else {
        S.push(ch);
      }
    }
    return S.empty();
  }
};