class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int>maxlen(26,0);
        int k=0;
        for(int i=0;i<s.size();i++){
            if(i>0 && ((s[i]-s[i-1]+26)%26==1)){
                k++;
            }else{
                k=1;
            }
            int idx=s[i]-'a';
            maxlen[idx]=max(maxlen[idx],k);
        }
        return accumulate(maxlen.begin(),maxlen.end(),0);
    }
};