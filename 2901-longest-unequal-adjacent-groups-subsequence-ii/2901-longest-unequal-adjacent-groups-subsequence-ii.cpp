class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && 
                    words[i].size() == words[j].size() && 
                    hammingDistance(words[i], words[j]) == 1) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
        }
        
        int max_len = *max_element(dp.begin(), dp.end());
        int idx = find(dp.begin(), dp.end(), max_len) - dp.begin();
        
        vector<string> result;
        while (idx != -1) {
            result.push_back(words[idx]);
            idx = prev[idx];
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
    
private:
    int hammingDistance(const string& a, const string& b) {
        int dist = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                dist++;
            }
        }
        return dist;
    }
};