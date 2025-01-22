class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> height;
        int rowSize = isWater.size();
        int colSize = isWater[0].size();
        vector<vector<bool>> visited(rowSize, vector<bool>(colSize, 0));
        queue<pair<int, int>> BFS;

        int dRow[] = { -1, 0, 1, 0 };
        int dCol[] = { 0, 1, 0, -1 };

        for (int i = 0; i < rowSize; i++) 
            for (int j = 0; j < colSize; j++) 
                if (isWater[i][j]) {
                    BFS.push({i, j});
                    isWater[i][j] = 0;
                    visited[i][j] = 1;
                }

        while (!BFS.empty()) {
            int row = BFS.front().first;
            int col = BFS.front().second;
            for (int i = 0; i < 4; i++) {
                int R = row + dRow[i];
                int C = col + dCol[i];
                if (R < 0 || C < 0 || R >= rowSize || C >= colSize)
                    continue;
                if (!visited[R][C]) {
                    isWater[R][C] = isWater[row][col] + 1;
                    BFS.push({R, C});
                    visited[R][C] = 1;
                }
            }
            BFS.pop();
        }
        return isWater;
    }
};