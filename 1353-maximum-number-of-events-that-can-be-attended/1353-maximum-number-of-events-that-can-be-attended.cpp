class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int ans = 0;
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>>pq;
        int day = 1;
        int i = 0;
        while(i < n || !pq.empty())
        {
            int j = i;
            while(j < n && events[j][0] == day)
            {
                pq.push({events[j][1]});
                j++;
            }
            if(!pq.empty())
            {
                if(pq.top() < day)
                pq.pop();

                else if(pq.top() >= day)
                {
                    pq.pop();
                    ans++;
                    day++;
                }
            }
            else day++;
      
            i = j;
        }
        return ans;
    }
};