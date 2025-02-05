class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        string a=s1;
        string b=s2;
       
         
         int diff=0;
        int n=s1.length();

        for(int i=0;i<n;i++){
             if(a[i]!=b[i]){
                 diff++;
                 if(diff>2) return false;
             }
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());

         if(s1!=s2) return false;

        return true;
    }
};