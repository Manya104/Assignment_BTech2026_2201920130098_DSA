class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int maxlen = 0;
        
        for (int cur = 2; cur < n; cur++) {
            int start = 0, end = cur - 1;
            while (start < end) {
                int sum = arr[start] + arr[end];
                if (sum < arr[cur]) {
                    start++;
                }
                else if (sum > arr[cur]) {
                    end--;
                }
                else {
                    dp[end][cur] = dp[start][end] + 1;
                    maxlen = max(maxlen, dp[end][cur]);
                    start++;
                    end--;
                }
            }
        }
        return maxlen > 2 ? maxlen : 0; 
    }
};