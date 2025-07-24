
class Solution {
public:
    int xorDfs(int i, int par, vector<int>&nums, vector<vector<int>>& adj, vector<int>& dp, vector<int>& parent){
        int xor1 = nums[i];
        parent[i] = par;
        for(auto& child: adj[i]){
            if(child==par) continue;
            dp[child] = xorDfs(child, i, nums, adj, dp, parent);
            xor1 = xor1^dp[child];
        }
        return xor1;
    }
    void dfs(int i, int par, long long& xor1, long long& thirdXor, long long& ans, vector<vector<int>>& adj, vector<int>& dp, vector<int>& parent){
        for(auto& child: adj[i]){
            if(child==par) continue;
            long long childXor = dp[child];
            if(child == parent[i]){
                childXor = dp[0]^dp[i];
            }
            long long parXor = xor1^childXor;
            ans = min(ans, max(thirdXor, max(childXor, parXor)) - min(thirdXor, min(childXor, parXor)));

            dfs(child, i, xor1, thirdXor, ans, adj, dp, parent);
        }
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>>adj(n);
        vector<int>dp(n);
        vector<int>parent(n);

        for(auto& e: edges){
            int a = e[0];
            int b = e[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dp[0] = xorDfs(0, -1, nums, adj, dp, parent);

        long long ans = 1e18;
        for(int i = 0; i<edges.size(); i++){
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            long long ans1 = 1e18, ans2 = 1e18;
            
            long long xor1 = dp[node1], xor2 = dp[node2];
            if(node1 == parent[node2])
            {    
                xor1 = dp[0]^xor2;
            }
            else 
            {
                xor2 = dp[0]^xor1;
            }
            dfs(node1, node2, xor1, xor2, ans1, adj, dp, parent);
            dfs(node2, node1, xor2, xor1, ans2, adj, dp, parent); 
            ans = min(ans, min(ans1, ans2));
        }

        return ans;
    }
};