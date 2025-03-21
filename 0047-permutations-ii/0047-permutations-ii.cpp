class Solution {
public:
    void perm(vector<int>nums, int i, vector<vector<int>>& ans){
        if (i>=nums.size()){ans.push_back(nums);return;}
        for (int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            perm(nums,i+1,ans);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        perm(nums,0,ans);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};