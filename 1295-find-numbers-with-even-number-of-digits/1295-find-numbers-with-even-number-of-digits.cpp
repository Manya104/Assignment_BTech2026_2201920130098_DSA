class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (auto n: nums) {
            if (n >= 10 && n <= 99) {
                res++;
                continue;
            }
            if (n >= 1000 && n <= 9999) {
                res++;
                continue;
            }
            if (n >= 100000)
                res++;
        }
        return res;
    }
};