class Solution {
public:
int solve(vector<vector<int>>&grid, int i, int j, vector<vector<int>>&vis){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>>q;
    q.push({i,j});
    // vector<vector<int>>vis(n, vector<int>(m,0));
    vis[i][j] = 1;
     int delrow[] = {-1, 0,1,0};
      int delcol[] = {0,1,0,-1};
      int ans =0;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        ans += grid[r][c];
        for(int i =0; i<4; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if(nrow>=0 &&nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]>0 && !vis[nrow][ncol]){
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }

    return ans;
}
    int findMaxFish(vector<vector<int>>& grid) {

        int n= grid.size();
        int m = grid[0].size();
        int count =0;
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j]>0 && !vis[i][j]){
                    int w = solve(grid,i,j, vis);
                    if(w>count){
                        count = w;
                    }
                }
            }
        }

        return count;
        
    }
};