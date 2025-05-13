class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {        
        int n=nums.size();
        priority_queue<pair<int,int>> maxH;

        for(int i=0;i<k;i++)
        {
            maxH.push({nums[i],i});
        }
        vector<int> ans;
        ans.push_back(maxH.top().first);
        for(int i=k;i<n;i++)
        {
            while(!maxH.empty() && maxH.top().second<=i-k)
            {
                maxH.pop();
            }
            maxH.push({nums[i],i});
            ans.push_back(maxH.top().first);

        }
        return ans;

    }
};