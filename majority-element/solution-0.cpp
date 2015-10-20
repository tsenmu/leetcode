class Solution {
public:
  int majorityElement(vector<int> &num) {
    unordered_map<int, int> m;
    for (int i = 0; i < num.size(); ++i) {
      m[num[i]] = m[num[i]] + 1;
    }
    int half = (num.size() >> 1);
    for (auto i = m.begin(); i != m.end(); ++i) {
      if (i->second >  half) {
        return i->first;
      }
    }
  }
};