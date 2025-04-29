class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n<k) return 0;
        int left =0 , maxfreq=0 ;
        int maxelement = *max_element(nums.begin(),nums.end());
        long long ans=0 ;
        for(int right =0 ; right < n ; ++right){
            if(nums[right]==maxelement){
                maxfreq++;
            }
            while(maxfreq>=k){
                ans += n-right;
            
            if(nums[left]==maxelement){
                maxfreq--;
            }
            left++;
            }
        }
        return ans;
    }
};