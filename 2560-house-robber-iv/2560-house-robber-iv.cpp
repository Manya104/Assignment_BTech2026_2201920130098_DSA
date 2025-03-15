class Solution {
public:
    int minCapability(vector<int>& nums, int k) 
    {
        int n = nums.size();
        if (n == 1) return nums[0];
        long long low = 1, high = 1e9, result = 0;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            int included = 0, excluded = 0;

            for (int i = 0; i < n; i++)
            {
                if (nums[i] <= mid) included++;
                int maxPrev = max(included, excluded);
                included = excluded;
                excluded = maxPrev;
            }

            if (max(included, excluded) >= k)
            {
                result = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return result;
    }
};
