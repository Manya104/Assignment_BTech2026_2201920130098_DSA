class Solution {
public:
    string smallestNumber(string pattern) {
        string res="";
        int num=1;stack<int>st;
        for(int i=0;i<=pattern.size();i++){
            st.push(num++);
            if(i==pattern.size()||pattern[i]=='I'){
                while(!st.empty()){
                    res+=to_string(st.top());
                    st.pop();
                }
            }
        }
        return res;
    }
};