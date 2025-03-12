class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int po=0,ne=0;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                po++;
            }
            else if(nums[i]<0){
                ne++;
            }
        }
        return max(po,ne);
    }
};