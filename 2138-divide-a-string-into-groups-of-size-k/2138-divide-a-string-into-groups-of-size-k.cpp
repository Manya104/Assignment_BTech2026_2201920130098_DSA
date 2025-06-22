class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();

        vector<string> st;
        int cnt=0;
        string temp="";
        for(int i=0;i<n;i++){
            cnt++;
            temp+=s[i];

            if(cnt==k){
                st.push_back(temp);
                temp="";
                cnt=0;
            }
        }

        if(temp==""){
            return st;
        }
        for(int i=k-cnt;i>0;i--){
            temp+=fill;
        }
        st.push_back(temp);
    
        return st;
    }
};