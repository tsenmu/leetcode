class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        
        vector<int> leaves;
        if (n == 1) {
            leaves.push_back(0);
            return leaves;
        }

        // Created the graph
        vector<unordered_set<int>> graph(n, unordered_set<int>());       
        for (int i = 0; i < edges.size(); ++i) {
            auto edge = edges[i];
            int v = edge.first;
            int u = edge.second;
            graph[v].insert(u);
            graph[u].insert(v);
        }

        // Find leaves
        
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == 1) {
                leaves.push_back(i);
            }
        }
        // Topological sort
        while (n > 2) {
            n -= leaves.size();
            vector<int> newLeaves;
            for (int i = 0; i < leaves.size(); ++i) {
                int u = leaves[i];
                for (auto it = graph[u].begin(); it != graph[u].end(); ++it) {
                    int v = *it;
                    graph[v].erase(u);
                    if (graph[v].size() == 1) {
                        newLeaves.push_back(v);
                    }
                }
            }
            leaves = newLeaves;
        }

        return leaves;
    }
};