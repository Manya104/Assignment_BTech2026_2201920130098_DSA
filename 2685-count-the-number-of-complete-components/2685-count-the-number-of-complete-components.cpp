class Solution {
public:
    void dfs(int src, vector<int>& vis, unordered_map<int, vector<int>>& adj,
             pair<int, int>& mp) {
        vis[src] = 1;
        mp.first++;
        mp.second += adj[src].size();

        for (auto nbr : adj[src]) {
            if (!vis[nbr])
                dfs(nbr, vis, adj, mp);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0);
        int completeCount = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                pair<int, int> temp = {0, 0};
                dfs(i, vis, adj, temp);

                if ((temp.first * (temp.first - 1)) == temp.second)
                    completeCount++;
            }
        }

        return completeCount;
    }
};