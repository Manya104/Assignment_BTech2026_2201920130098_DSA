class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mask = 0;
        int n = nums.size(); 

        int ans = 1; 
        mask = nums[0];
        int j = 0; 
        for(int i = 1; i < n; i++) {
            int el = nums[i];
            
            if((mask & el) != 0) {
                while(j <= i and ((mask & el) != 0)) {
                    ans = max(ans, i-j);
                    mask -= nums[j++];
                }
            } 
            mask += el; 
            
        }
        return max(ans, n-j);
    }
};