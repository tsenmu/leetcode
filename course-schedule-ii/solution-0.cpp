class Solution {
public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> ans;
    int in[numCourses];
    vector<int> out[numCourses];
    for (int i = 0; i < numCourses; ++i) {
      in[i] = 0;
    }

    for (int i = 0; i < prerequisites.size(); ++i) {
      int from = prerequisites[i].first;
      int to = prerequisites[i].second;
      out[from].push_back(to);
      in[to]++;
    }
    queue<int> Q;

    for (int i = 0; i < numCourses; ++i) {
      if (in[i] == 0) {
        Q.push(i);
      }
    }

    while (!Q.empty()) {
      int current = Q.front();
      Q.pop();
      ans.push_back(current);
      for (int i = 0; i < out[current].size(); ++i) {
        int to = out[current][i];
        in[to]--;
        if (in[to] == 0) {
          Q.push(to);
        }
      }
    }
    for (int i = 0; i < numCourses; ++i) {
      if (in[i] != 0) {
        return vector<int>();
      }
    }
    return ans;
  }
};