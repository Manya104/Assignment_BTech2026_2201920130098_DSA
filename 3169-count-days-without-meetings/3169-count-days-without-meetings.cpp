class Solution {
public:
    //TC = O(nlogn)  &&  SC = O(n)
    int countDays(int days, vector<vector<int>>& meetings) {
        int n  = meetings.size();

        sort(meetings.begin(), meetings.end());

        int st = 0;
        int end = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(meetings[i][0] > end) {
                ans += meetings[i][0] - end - 1;
            }

            end = max(meetings[i][1], end); //Note: The meetings may overlap.{Edge CASE}
        }

        if(end < days) { //{Edge CASE}
            ans += days-end;
        }

        return ans;
    }
};