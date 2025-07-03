class Solution {
public:

    int dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        int count = 1; 
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                count += dfs(neighbor, adj, visited);
            }
        }
        return count;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {

        int n = bombs.size();
        vector<vector<int>> adj(n);

        for(int i =0 ; i< bombs.size(); i++){
            long long node_x = bombs[i][0];
            long long node_y = bombs[i][1];
            long long r = bombs[i][2];


            for(int j =0; j<bombs.size(); j++){
                int count = 0;
                if (i==j)continue;

                long long x2 = bombs[j][0], y2 = bombs[j][1];
                long long dx = node_x - x2, dy = node_y - y2;
                long long dist = dx * dx + dy * dy;


                if(dist<=(long long)r*r){
                    adj[i].push_back(j);
                }
            }
        }

        int maxDetonated = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            maxDetonated = max(maxDetonated, dfs(i, adj, visited));
        }

        return maxDetonated;
    }
};