class Solution {
public:
  bool wordPattern(string pattern, string str) {
    vector<string> sequence;      
    bool inWord = false;
    string currentWord;
    for(int i = 0; i < str.length(); ++i) {
      if (!inWord) {
        if (str[i] != ' ') {
          inWord = true;
          currentWord.push_back(str[i]);
        }
      } else {
        if (str[i] == ' ') {
          inWord = false;
          sequence.push_back(currentWord);
          currentWord.clear();
        } else {
            currentWord.push_back(str[i]);
        }
      }
    }
    if (currentWord.length() > 0) {
      sequence.push_back(currentWord);
    }

    if (pattern.length() != sequence.size()) {
      return false;
    }
    
    map<string, char> M1;
    for (int i = 0; i < pattern.length(); ++i) {
      if (M1.count(sequence[i]) == 0) {
        M1[sequence[i]] = pattern[i];
      } else {
        if (M1[sequence[i]] != pattern[i]) {
          return false;
        }
      }
    }
    
    map<char, string> M2;
    for (int i = 0; i < pattern.length(); ++i) {
      if (M2.count(pattern[i]) == 0) {
        M2[pattern[i]] = sequence[i];
      } else {
        if (M2[pattern[i]] != sequence[i]) {
          return false;
        }
      }
    }
    return true;
  }
};