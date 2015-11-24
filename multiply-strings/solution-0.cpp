class Solution {
public:
  string multiply(string num1, string num2) {

    if (num1.size() > num2.size()) {
      return multiply(num2, num1);
    }

    string ans;

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());


    for (int i = 0; i < num1.size(); ++i) {
      string partialAns;
      int increment = 0;
      int n1 = charToInt(num1[i]);
      for (int j = 0; j < num2.size(); ++j) {
        int n2 = charToInt(num2[j]);
        int product = n1 * n2 + increment;
        increment = product / 10;
        product = product % 10;
        partialAns.push_back(intToChar(product));
      } 

      if (increment) {
        partialAns.push_back(intToChar(increment));
      }

      partialAns = decimalLeftShift(partialAns, i);

      ans = add(ans, partialAns);
    }

    ans = reduceLeadingZero(ans);

    reverse(ans.begin(), ans.end());

    if (ans.size() == 0) {
      return "0";
    }
    return ans;
  }


  string decimalLeftShift(string num, size_t shift) {
    string zeros;
    for (int i = 0; i < shift; ++i) {
      zeros.push_back('0');
    }
    return zeros + num;
  }

  string reduceLeadingZero(string num) {
    string ans;
    bool skippedLeadingZeros = false;
    for (int i = num.size() - 1; i >= 0; --i) {
      if (!skippedLeadingZeros) {
        if (num[i] != '0') {
          skippedLeadingZeros = true;
        }
      } 

      if (skippedLeadingZeros) {
        ans.push_back(num[i]);
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }

  string add(string num1, string num2) {

    string ans; 

    int increment = 0;
    int i = 0; 
    int j = 0;

    while (i < num1.size() || j < num2.size() || increment) {
      int sum = increment; 

      if (i < num1.size()) {
        sum += charToInt(num1[i]);
        i++;
      }

      if (j < num2.size()) {
        sum += charToInt(num2[j]);
        j++;
      }

      increment = sum / 10;
      sum = sum % 10;
      ans.push_back(intToChar(sum));
    }

    return ans;
  }

  int charToInt(char ch) {
    return ch - '0';
  }

  char intToChar(int digit) {
    return '0' + digit;
  }
};



