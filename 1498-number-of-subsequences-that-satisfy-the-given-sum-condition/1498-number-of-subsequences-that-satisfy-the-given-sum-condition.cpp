class Solution {
public:
    int numSubseq(vector<int>& a, int target) {
        int mod = 1e9 + 7;
        int n = a.size();
        sort(a.begin(), a.end());

        vector<int> power(n, 1);
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }

        int l = 0, r = n - 1, result = 0;

        while (l <= r) {
            if (a[l] + a[r] <= target) {
                result = (result + power[r - l]) % mod;
                ++l;
            } else {
                --r;
            }
        }
        return result;
    }
};