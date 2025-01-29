 class Solution {
private:
    bool hasCycle(vector<vector<int>>& adjList, int src, int n) {
        queue<pair<int, int>> q;
        vector<bool> visited(n + 1, false);
        q.push({src, -1});
        visited[src] = true;

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                } else if (neighbor != parent) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adjList(n + 1);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);

            if (hasCycle(adjList, u, n)) {
                return edge;
            }
        }

        return {};
    }
};