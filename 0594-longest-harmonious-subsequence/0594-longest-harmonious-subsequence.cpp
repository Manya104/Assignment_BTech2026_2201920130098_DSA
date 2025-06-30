class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left = 0;
        int n = nums.size();
        int ans = 0;
        int curr = 0;
        for(int i = 0;i<n;i++){
            while((nums[i] -nums[left]) >1){
                left++;
            }
            if(nums[i] - nums[left] == 1)
            ans = max(ans,i-left+1);
        }
        return ans;
    }
};