class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());long long count=0;
        for(int i=0;i<nums.size();i++)
        {
            long long  lb=lower_bound(nums.begin(),nums.end(),lower-nums[i])-nums.begin();
            long long ub=upper_bound(nums.begin(),nums.end(),upper-nums[i])-nums.begin()-1;
            if(i<lb)count+=(ub-lb)+1;
            if(i>=lb&&i<=ub)count+=(ub-i);
            if(i>ub)count+=0;
        }
        return count;
    }
};