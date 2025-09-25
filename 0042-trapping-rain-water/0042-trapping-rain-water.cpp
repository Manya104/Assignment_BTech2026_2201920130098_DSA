class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int res=0;
        int leftmax=height[l],rightmax=height[r];
        if(height.empty()){
            return 0;
            }
        while(l<r){
            if(leftmax<rightmax){
                l++;
                leftmax=max(leftmax,height[l]);
                res+=leftmax-height[l];
            }else{
                r--;
                rightmax=max(rightmax,height[r]);
                res+=rightmax-height[r];
            }
        }
        return res;
    }
};