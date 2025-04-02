class Solution {
public:
    int countKeyChanges(string s) {
        int count=0;
        for(int j=0;j<s.size();j++){
            if(65<=s[j] && s[j]<=90){
                s[j]+=32;
            }
        }
        for(int i=0;i<s.size()-1;i++){
            if(s[i]!=s[i+1]){
                count++;
            }
        }
        
       return count; 
    }
};