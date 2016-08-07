class Solution {
protected:
    bool dfs(int node, const vector<set<int>>& graph, vector<bool>& visited) {
        if (visited[node]) {
            return false;
        }
        visited[node] = true;
        for (int child : graph[node]) {
            if (!visited[child]) {
                dfs(child, graph, visited);
            }
        }
        return true;
    }
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<set<int>> graph(n, set<int>());       
        vector<bool> visited(n, false);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i].first;
            int v = edges[i].second;
            graph[u].insert(v);
            graph[v].insert(u);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (dfs(i, graph, visited)) {
                ++ans;
            }
        }
        return ans;
    }
};