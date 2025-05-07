class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const int n = moveTime.size();
        const int m = moveTime[0].size();
        const int INF = 2'000'000'000;
        
        vector<vector<int>> d(n, vector<int>(m, INF));
        d[0][0] = 0;
        
        using Vertex = tuple<int, int, int>; // distance, i, j
        priority_queue<Vertex, vector<Vertex>, greater<Vertex>> queue;
        queue.push({0, 0, 0});
        
        while (!queue.empty()) {
            auto [distance, i, j] = queue.top();
            queue.pop();
            
            if (distance > d[i][j]) continue;
            
            vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (auto [di, dj] : directions) {
                int nextI = i + di;
                int nextJ = j + dj;
                
                if (nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < m) {
                    int nextDistance = max(distance, moveTime[nextI][nextJ]) + 1;
                    if (d[nextI][nextJ] > nextDistance) {
                        d[nextI][nextJ] = nextDistance;
                        queue.push({nextDistance, nextI, nextJ});
                    }
                }
            }
        }
        
        return d[n - 1][m - 1];
    }
};