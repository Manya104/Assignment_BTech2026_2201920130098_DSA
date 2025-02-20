class Solution {
public:
    int smallestNumber(int n, int t) {
        if (t == 1 || n % 10 == 0) return n;
        int nn;
        while (1) {
            int product = 1;
            nn = n;
            while (nn > 0) {
                int digit = nn % 10;
                product *= digit;
                nn /= 10;
            }
            if (product % t == 0) return n;
            n++;
        }
        return 0;
    }
};