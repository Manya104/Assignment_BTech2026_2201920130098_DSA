class Solution {
public:
    void dfs(int u, vector<vector<int>>& g, vector<bool>& vis, long long& cnt) {
        vis[u] = true; cnt++;
        for(int v : g[u]) if(!vis[v]) dfs(v, g, vis, cnt);
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto& e : edges) g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        vector<bool> vis(n, false);
        long long ans = 0, sum = 0;
        for(int i = 0; i < n; ++i)
            if(!vis[i]) {
                long long cnt = 0;
                dfs(i, g, vis, cnt);
                ans += cnt * sum;
                sum += cnt;
            }
        return ans;
    }
};
