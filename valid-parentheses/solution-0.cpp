class Solution {
public:
    bool isValid(string s) {
        stack<char> symbolStack;

        for (int i = 0; i < s.length(); ++i) {
            char symbol = s[i];
            char topSymbol = ' ';
            if (!symbolStack.empty()) {
              topSymbol = symbolStack.top();
            }
            switch (symbol) {
              case '(':
              case '{':
              case '[':
                symbolStack.push(symbol);
                break;
              case ')':
              case '}':
              case ']':
                if (isMatch(topSymbol, symbol)) {
                  symbolStack.pop();
                } else {
                  return false;
                }
                break;
            }
        }

        return symbolStack.empty();
    }

    bool isMatch(char left, char right) {
      return left == '(' && right == ')' || left == '[' && right == ']' 
        || left == '{' && right == '}';
    }
};