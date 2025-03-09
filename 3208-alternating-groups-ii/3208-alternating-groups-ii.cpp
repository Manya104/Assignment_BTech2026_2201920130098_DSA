class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& co, int k) {
        int n = co.size();
        vector<int> b(co.begin(), co.end());
        for (int i = 0; i < n; i++) {
            b.push_back(co[i]);
        }

        int j = 1;
        int i = 0;
        int cnt = 1;
        int ans = 0;
        while (j < 2 * n && i < n) {
            if (cnt == k) {
                ans++;
                i++;
                cnt--;
            }
            
            if (b[j - 1] != b[j]) {
                cnt++;
            } else {
                i = j;
                cnt = 1;
            }
            j++;
        }
        return ans;
    }
};