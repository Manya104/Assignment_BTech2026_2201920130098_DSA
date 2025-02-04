class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int maxSum = nums[0];
        int n = nums.size();
        for(int i = 0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                sum += nums[i+1];
            }
            else{
                sum = nums[i+1];
            }
            maxSum = max(sum,maxSum);
        }
        return maxSum;
        
    }
};