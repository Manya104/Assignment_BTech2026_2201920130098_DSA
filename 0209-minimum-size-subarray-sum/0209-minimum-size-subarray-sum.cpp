
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, sum = 0;
        int mindis = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum >= target) {
                mindis = min(mindis, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return mindis == INT_MAX ? 0 : mindis;
    }
};
