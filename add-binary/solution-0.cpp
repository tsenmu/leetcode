class Solution {
public:
  string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string ans;
    int i = 0;
    int j = 0;
    int increment = 0;
    while (i < a.size() && j < b.size()) {
      int digitA = a[i] - '0';
      int digitB = b[i] - '0';
      int sum = digitA + digitB + increment;
      increment = (sum >> 1);
      sum = (sum & 1);
      ans.push_back((char)(sum + '0'));
      i++;
      j++;
    }
    
    while (i < a.size()) {
        int digitA = a[i] - '0';
        int sum = digitA + increment;
        increment = (sum >> 1);
        sum = (sum & 1);
        ans.push_back((char)(sum + '0'));
        i++;
    }
    
    while (j < b.size()) {
        int digitB = b[j] - '0';
        int sum = digitB + increment;
        increment = (sum >> 1);
        sum = (sum & 1);
        ans.push_back((char)(sum + '0'));
        j++;
    }
    
    while (increment != 0) {
        int sum = increment;
        increment = (sum >> 1);
        sum = (sum & 1);
        ans.push_back((char)(sum + '0'));

    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};