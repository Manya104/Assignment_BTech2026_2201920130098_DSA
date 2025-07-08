class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            int next = lower_bound(events.begin(), events.end(), events[i][1] + 1,
                [](const vector<int>& e, int day) {
                    return e[0] < day;
                }) - events.begin();

            for (int j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i + 1][j], events[i][2] + dp[next][j - 1]);
            }
        }
        return dp[0][k];
    }
};