class Solution {
protected:
    bool dfs(
        unordered_map<string, set<string>>& graph, 
        unordered_map<string, unordered_map<string, int>>& count,
        vector<string>& ans,
        int total) {

        if (total + 1 == ans.size()) {
            return true;
        }

        const string& node = ans[ans.size() - 1];
        for (const string& dest : graph[node]) {
            if (count[node][dest] > 0) {
                count[node][dest]--;
                ans.push_back(dest);
                if (dfs(graph, count, ans, total)) {
                    return true;
                }
                count[node][dest]++;
                ans.pop_back();
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, set<string>> graph;
        unordered_map<string, unordered_map<string, int>> count;
        for (auto ticket : tickets) {
            graph[ticket.first].insert(ticket.second);
            count[ticket.first][ticket.second]++;
        }
        vector<string> ans;
        ans.push_back("JFK");
        dfs(graph, count, ans, tickets.size());
        return ans;
    }
};