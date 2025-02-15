class Solution {
public:
    bool canSplit(string s,int idx,int target,int sum){
        if(idx==s.size())  return sum==target;
        if(target<sum) return false;
        int num=0;
        for(int i=idx;i<s.size();i++){
            num=num*10+(s[i]-'0');
            if(canSplit(s,i+1,target,sum+num)) return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int total=1;
        for(int i=2;i<=n;i++){
            int sq=pow(i,2);
            if(canSplit(to_string(sq),0,i,0))
                total+=sq;
        }
        return total;
    }
};