class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();

        vector<long long>minSum(n,LLONG_MAX),maxSum(n,LLONG_MIN);
        
        priority_queue<int>maxHeap;
        priority_queue<int, vector<int>, greater<int>>minHeap;

        for(int i = 0;i < n / 3;i++){
            maxHeap.push(nums[i]);
        }

        minSum[(n / 3) - 1] = accumulate(nums.begin(),nums.begin() + n / 3,0ll);

        for(int st = (n / 3);st < n;st++){
            if(maxHeap.top() <= nums[st]){
                minSum[st] = minSum[st - 1];
            }else{
                minSum[st] = minSum[st - 1] - maxHeap.top() + nums[st];
                maxHeap.pop();
                maxHeap.push(nums[st]); 
            }
        }

        for(int i = 0;i < n / 3;i++){
            minHeap.push(nums[n - i - 1]);
        }

        maxSum[(2 * n) / 3] = accumulate(nums.rbegin(),nums.rbegin() + n / 3,0ll);

        for(int st = ((2 * n) / 3) - 1;st >= 0;st--){
            if(minHeap.top() >= nums[st]){
                maxSum[st] = maxSum[st + 1];
            }else{
                maxSum[st] = maxSum[st + 1] - minHeap.top() + nums[st];
                minHeap.pop();
                minHeap.push(nums[st]); 
            }
        }

        long long minDiff = LLONG_MAX;

        for(int i = (n / 3) - 1;i < (2 * n) / 3;i++){
            minDiff = min(minSum[i] - maxSum[i + 1] + 0LL,minDiff);
        }

        return minDiff;
    }
};