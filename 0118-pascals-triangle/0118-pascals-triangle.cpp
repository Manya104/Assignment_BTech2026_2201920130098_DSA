class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result;
        result.push_back({1});
        for(int row=1;row<numRows;row++){
            vector<int>newrow;
            newrow.push_back(1);
            vector<int>prevrow=result[row-1];
            for(int i=1;i<row;i++){
                newrow.push_back(prevrow[i]+prevrow[i-1]);
            }
            newrow.push_back(1);
            result.push_back(newrow);
        }
        return result;
        
    }
};