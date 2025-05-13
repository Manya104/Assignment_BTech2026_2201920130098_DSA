class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int>freq(30);
        const int mod = 1e9+7;
        int n = s.size();
        for(auto ch : s){
            freq[ch-'a']++;
        }
        for(int i = 0 ; i<t ; i++){
            for(int i = 26 ;i>0 ; i--)freq[i] = freq[i-1];
            freq[0] = freq[26];
            freq[1] += freq[26];
            freq[1]%=mod;
        }
        int ans = 0;
        for(int i = 0 ;i<26 ; i++){
            ans += freq[i];
            ans %= mod;
        }
        return ans;
    }
};