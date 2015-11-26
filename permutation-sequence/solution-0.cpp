class Solution {
public:
  Solution() {
    string visited(9, 'f');        
    string current; 
    dfs(current, visited); 
  }
  vector<string> result;

  void dfs(string& current, string& visited) {
    if (current.length() == 9) {
      result.push_back(current);
      return;
    }

    for (int i = 0; i < 9; ++i) {
      if (visited[i] == 'f') {
        current.push_back('0' + (i + 1));
        visited[i] = 't';

        dfs(current, visited);

        current.pop_back();
        visited[i] = 'f';
      }
    }
  }

  string getPermutation(int n, int k) {


    string ans = result[k - 1];
    for (int i = 0; i < ans.length(); ++i) {
      ans[i] -= (k - 1);
    }
    return ans.substr(9 - k);
  }
};