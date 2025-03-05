class Solution {
public:
    long long coloredCells(int n) {
        if(n==1) return 1;
        if(n==2) return 5;
        long long ans = 5, pre = 8;
        for(int i=3; i<=n; i++){
            ans += pre;
            pre = 4*i;
            //cout<<
        }
        return ans;
    }
};