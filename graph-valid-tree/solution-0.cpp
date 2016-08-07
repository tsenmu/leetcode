class Solution {
protected:
    bool dfs(int node, int last, vector<set<int>>& graph, vector<bool>& visited) {
        visited[node] = true;

        for (int child : graph[node]) {
            if (child == last) {
                continue; 
            }

            if (visited[child]) {
                return false; 
            }

            if (!dfs(child, node, graph, visited)) {
                return false;
            }
        }
        return true;
    }
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<set<int>> graph(n, set<int>());
        vector<bool> visited(n, false);
        int start = -1;
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i].first;
            int v = edges[i].second;
            graph[u].insert(v);
            graph[v].insert(u);
            if (start == -1) {
                start = u;     
            }
        }

        if (start == -1) {
            if (n == 1) {
                return true;
            } else {
                return false;
            }
        }
    
        if (!dfs(start, -1, graph, visited)) {
            return false;
        }

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }
};