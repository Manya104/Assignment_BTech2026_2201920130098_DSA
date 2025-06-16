class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int len=nums.size();
        vector<int> kens;
        for(int i=0;i<len-1;i++){
            for(int j=i+1;j<len;j++){
                if(nums[i]<nums[j]){
                    kens.push_back(nums[j]-nums[i]);
                    
                }
            }
        }
        if(kens.size()>0){
            int max=*max_element(kens.begin(), kens.end());
            return max;

        }
        return -1;
        
    }
};