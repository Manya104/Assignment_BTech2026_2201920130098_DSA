class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long n = size(nums), ret = n * --n / 2, i = 0;
        for (map<int, int> mp; int j : nums) ret -= mp[j - ++i]++;
        return ret;
    }
};