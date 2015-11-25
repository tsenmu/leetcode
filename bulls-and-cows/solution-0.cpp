class Solution {
public:
  string getHint(string secret, string guess) {
    int numA = 0;
    int numB = 0;
    int counts[20];
    memset(counts, 0, sizeof counts);
    for (int i = 0; i < secret.length(); ++i) {
      if (secret[i] == guess[i]) {
        numA++;
      } else {
        counts[secret[i] - '0']++;
        counts[guess[i] - '0' + 10]++;
      }
    }
    for (int i = 0; i < 10; ++i) {
      numB += counts[i] >  counts[i + 10] ? counts[i + 10] : counts[i];
    }
    ostringstream oss;
    oss << numA << "A" << numB << "B";
    return oss.str();
  }
};