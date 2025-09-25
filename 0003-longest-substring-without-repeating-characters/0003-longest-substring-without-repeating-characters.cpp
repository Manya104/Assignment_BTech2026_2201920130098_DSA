class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>pos;
        int l=0,ans=0;
        for(int r=0;r<s.size();r++){
        if(pos.count(s[r])&& pos[s[r]]>=l){
            l=pos[s[r]]+1;
        }
        pos[s[r]]=r;
        ans=max(ans,r-l+1);
        }
        return ans;
    }
};