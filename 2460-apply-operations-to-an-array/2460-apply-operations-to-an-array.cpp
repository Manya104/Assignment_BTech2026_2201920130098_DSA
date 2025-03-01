class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) 
        if (nums[i] == nums[i + 1]) nums[i] *= 2,nums[i + 1] = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (count(nums.begin() + i, nums.end(), 0) == nums.size() - i)
                break;
            if (nums[i] == 0) nums.erase(nums.begin() + i), nums.push_back(0), i--;
        }
        return nums;
    }
};