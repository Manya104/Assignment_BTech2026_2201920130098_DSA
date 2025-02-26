class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0;
        int currMaxSum = 0, currMinSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            // Maximum subarray sum
            currMaxSum += nums[i];
            maxSum = max(maxSum, currMaxSum);
            if (currMaxSum < 0) {
                currMaxSum = 0;
            }

            // Minimum subarray sum
            currMinSum += nums[i];
            minSum = min(minSum, currMinSum);
            if (currMinSum > 0) {
                currMinSum = 0;
            }
        }
        
        return max(abs(maxSum), abs(minSum));
    }
};