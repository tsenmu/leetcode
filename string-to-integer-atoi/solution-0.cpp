class Solution {
public:
    int toDigit(char ch) {
      if (ch >= '0' && ch <= '9') {
        return int(ch - '0');
      } else {
        return -1;
      }
    }

    int round(long long number) {
      if (number > INT_MAX) {
        return INT_MAX;
      } else if (number < INT_MIN) {
        return INT_MIN;
      } else {
        return number;
      }
    }

    int myAtoi(string str) {
      int i = 0;
      while (i < str.size() && str[i] == ' ') {
        i++;
      }

      int sign = 1;
      if (i < str.size() && (str[i] == '+' || str[i] == '-')) {
        if (str[i] == '-') {
          sign = -1;
        }
        i++;
      }

      long long ans = 0;

      while (i < str.size()) {
        int digit = toDigit(str[i]);
        if (digit == -1) {
          return round(sign * ans);
        } 
        ans = 10 * ans + digit;
        if (sign == 1) {
          if (ans > INT_MAX) {
            return INT_MAX;
          }
        } else {
          if (ans < INT_MIN) {
            return INT_MIN;
          }
        }
        i++;
      } 
      return round(sign * ans);
    }
};