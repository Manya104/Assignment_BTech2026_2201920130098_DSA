#define ll long long;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        int currMaxi = nums[n-1];
        vector<int> nextMax(n, -1);
        nextMax[n-1] = nums[n-1];
        
        for(int i=n-2;i>=0;i--){
            if(nums[i] >= currMaxi){
                nextMax[i] = currMaxi;
            }
            if(nums[i] > currMaxi){
                currMaxi = nums[i];
            }
            else nextMax[i] = currMaxi;
        }

        for(auto& it:nextMax) cout << it << " ";

        int maxi = nums[0];

        for(int i=1;i<n-1;i++){
            if(nums[i] <= maxi){
                ans = max(ans, (long long)(maxi - nums[i]) * nextMax[i] * 1LL);
            }
            else maxi = nums[i];
        }

        return ans;
    }
};