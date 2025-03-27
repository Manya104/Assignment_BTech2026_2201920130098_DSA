class Solution {
public:
    int dominant_element(vector<int>& nums, int n)
    {
        unordered_map<int, int> mp;
        for(auto x : nums)
            mp[x]++;
        int max_freq = 0, dom;

        for(auto it : mp)
        {
            if(max_freq < it.second)
            {
                max_freq = it.second;
                dom = it.first;
            }
        }     
        return dom;
    }

    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int dom =  dominant_element(nums, n);
        vector<int> freq_prefix(n, 0);
        
        if(nums[0] == dom)
            freq_prefix[0] = 1;

        for(int i = 1; i < n; i++)
        {
            if(nums[i] == dom)
                freq_prefix[i] += 1 + freq_prefix[i - 1];
            else
                freq_prefix[i] += freq_prefix[i - 1];
        }

        int total_dom_freq = freq_prefix[n - 1];

        for(int i = 0; i < n - 1; i++)
        {
            int left_size = i + 1, right_size = n - i - 1;
            int left_dom_freq = freq_prefix[i], right_dom_freq = total_dom_freq - freq_prefix[i];

            if(left_dom_freq > left_size / 2 && right_dom_freq > right_size / 2)
                return i; 
        }
        
        return -1;    
    }
};