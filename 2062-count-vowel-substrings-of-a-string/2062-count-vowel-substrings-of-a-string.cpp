class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_map<char,int> mp;
        int ans = 0;
        string s = "aeiou";

        for(auto x:s)
            mp[x]++;

        for(int i=0;i<word.size();i++){
            set<char> st;
            for(int j=i;j<word.size();j++){
                if(mp.find(word[j]) != mp.end()){
                    st.insert(word[j]);
                    if(st.size() >= 5)
                        ans++;
                }else{
                    // st.clear();
                    break;
                }
            }
        }
        return ans;
    }
};