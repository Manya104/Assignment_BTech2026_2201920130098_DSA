class Solution {
    bool f(int n, string &ans, unordered_map<string, int>& mp){
        if(ans.size() == n){
            if(mp.find(ans) == mp.end()){
                return true;
            }
            return false;
        }
        ans.push_back('0');
        if(f(n, ans, mp)) return true;  
        ans.pop_back();

        ans.push_back('1');
        if(f(n, ans, mp)) return true;
        ans.pop_back();
        
        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        unordered_map<string, int> mp;
        for(string it:nums){
            mp[it] = 1;
        }
        f(n, ans, mp);
        return ans;
    }
};