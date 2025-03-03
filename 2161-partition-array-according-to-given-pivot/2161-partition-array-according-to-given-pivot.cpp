class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> res(n,pivot);
        int i=0,ir=0,j=n-1,jr=n-1;
        while(i<n && j>=0) {
            if(nums[i]<pivot)
                res[ir++]=nums[i];
            if(nums[j]>pivot)
                res[jr--]=nums[j];
            i+=1;
            j-=1;
        }
        return res;
    }
};