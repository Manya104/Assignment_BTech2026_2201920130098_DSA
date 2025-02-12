class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int>mp;
        int val=-1;
        for(int i:nums){
            int temp=i,sum=0;
            while(temp!=0){
                sum+=temp%10;
                temp=temp/10;
            }
            if(mp.find(sum)!=mp.end()){
                val=max(mp[sum]+i,val);
            }
            mp[sum]=max(i,mp[sum]);
        }
        
        return val;
    }
};