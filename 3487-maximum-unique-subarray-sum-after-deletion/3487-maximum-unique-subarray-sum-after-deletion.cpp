class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = INT_MIN, currSum = 0;
        unordered_map<int, bool> seen;

        for (auto &it: nums) {
            if (it < 0) { ans = max(ans, it); continue; }
            if (seen[it]) continue;
            seen[it] = true;
            currSum += it;
            ans = max(ans, currSum);
        }

        return ans;
    }
};