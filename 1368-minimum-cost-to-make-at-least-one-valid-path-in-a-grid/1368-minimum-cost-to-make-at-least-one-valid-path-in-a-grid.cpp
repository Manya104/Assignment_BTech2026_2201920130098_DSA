class Solution {
public:
    #define P pair <int,pair <int,int>>
    
    int minCost(vector<vector<int>>& grid) {
        // dijkstras algorithm
        // can modify the cell at cost = 1
        int m = grid.size();
        int n = grid[0].size();
        priority_queue <P, vector <P>, greater <P>> q;
        vector <vector <int>> distance(m,vector <int>(n,INT_MAX));
        distance[0][0] = 0;
        q.push({0,{0,0}});
        vector <int> rowPos = {-1,0,1,0};
        vector <int> colPos = {0,-1,0,1};
        while(!q.empty()) {
            P top = q.top();
            q.pop();
            int cost = top.first;
            int row = top.second.first;
            int col = top.second.second;
            // nextMove without 0 cost
            int newRow,newCol;
            if(grid[row][col] == 1) {
                newRow = row;
                newCol = col + 1;
            }
            else if(grid[row][col] == 2) {
                newRow = row;
                newCol = col-1;
            }
            else if(grid[row][col] == 3) {
                newRow = row + 1;
                newCol = col;
            }
            else {
                newRow = row - 1;
                newCol = col;
            }
            for(int i = 0;i<4;i++) {
                int row1 = row + rowPos[i];
                int col1 = col + colPos[i]; 
                if(row1 >= 0 && row1 < m && col1 >= 0 && col1 < n) {
                    if(row1 == newRow && col1 == newCol) {
                        // 0 cost
                        if(distance[row1][col1] > cost) {
                            distance[row1][col1] = cost;
                            q.push({cost,{row1,col1}});
                        }
                    }
                    else {
                        // 1 cost and change direction
                        int newCost = cost + 1;
                        if(distance[row1][col1] > newCost) {
                            distance[row1][col1] = newCost;
                            q.push({newCost,{row1,col1}});
                        }
                    }
                }
            }
        }

        return distance[m-1][n-1];
    }
};