class Solution {
public:
  vector<vector<int>> result;
  void dfs(vector<int>& res, vector<int>& visited, vector<int>& num, vector<int>& amount, int total) {
    if (res.size() == total) {
      result.push_back(res);
    }

    for (int i = 0; i < num.size(); ++i) {
      for (int j = 0; j < amount[i]; ++j) {
        if (visited[i] < amount[i]) {
          res.push_back(num[i]);
          visited[i]++;

          dfs(res, visited, num, amount, total);

          res.pop_back(num[i]);
          visited[i]--;
        }
      }
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {

    map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
      m[nums[i]]++;
    }

    vector<int> num;
    vector<int> amount;

    for (auto it = m.begin(); it != m.end(); ++it) {
      num.push_back(it->first);
      amount.push_back(it->second);
    }

    vector<int> visited(num.size(), 0);
    vector<int> res;

    dfs(res, visited, num, amount, nums.size());
    return result;
  }
};