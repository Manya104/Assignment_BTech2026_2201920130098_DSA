class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        long long top_sum = 0, bottom_sum = 0;

        for (int i = 0; i < n; ++i)
            top_sum += grid[0][i];

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            top_sum -= grid[0][i];
            ans = min(ans, max(top_sum, bottom_sum));
            bottom_sum += grid[1][i];
        }

        return ans;
    }
};