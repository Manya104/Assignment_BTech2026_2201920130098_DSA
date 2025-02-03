class Solution {
public:
    int lengthStrictlyIncreasingDecreasingSubarray(vector<int> nums){
        int lengthInc = 1;
        int maxLengthInc = 1;
        int lengthDec = 1;
        int maxLengthDec = 1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] < nums[i+1]){
                lengthInc += 1;
                maxLengthInc = max(lengthInc, maxLengthInc);
                lengthDec = 1;
            }
            else if(nums[i] > nums[i+1]){
                lengthDec += 1;
                lengthInc = 1;
                maxLengthDec = max(lengthDec, maxLengthDec);
            }
            else{
                lengthInc = 1;
                lengthDec = 1;
            }
        }
        return max(maxLengthInc, maxLengthDec);
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        return lengthStrictlyIncreasingDecreasingSubarray(nums);
    }
};