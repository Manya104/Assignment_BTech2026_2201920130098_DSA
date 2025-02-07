class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
         unordered_map<int, int> mp;  
        unordered_map<int, int> balls;  
        int s = queries.size();
        vector<int> result(s, 0);
        int cnt = 0;
        for (int i = 0; i < s; i++) {
            int ball = queries[i][0];
            int col = queries[i][1];
            if (balls[ball]) {
                mp[balls[ball]]--;
                if (!mp[balls[ball]]) {
                    cnt--;
                }
            }
            balls[ball] = col;
            mp[col]++;
            if (mp[col] == 1) {
                cnt++;
            }
            result[i] = cnt;
        }
        return result;
    }
};