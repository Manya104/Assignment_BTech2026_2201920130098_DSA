class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> v = {1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969};
        int i = 14;
        if ( n > v[14] + 2*v[13]) return false; // just a check to return false if we see any number greater than approx 8000000 as no distinct power of 3 can add up to it while n <= 10^7 
        while (n > 0 && i >= 0){
            if (v[i] > n) {
                i--;
                continue;
            }
            n = n - v[i];
            i--;
        }
        if ( n == 0 ) return true;
        return false;
    }
};