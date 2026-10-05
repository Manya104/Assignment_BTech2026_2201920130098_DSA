class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>res(heights.size());
        for(int i=0;i<heights.size();i++){
            res[i]=heights[i];
        }
        sort(res.begin(),res.end());
        int cnt=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=res[i]){
                cnt++;
            }
        }
        return cnt;
        
    }
};