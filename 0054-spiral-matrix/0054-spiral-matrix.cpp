class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int>res;
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0,j=-1;
        int dir=1;
        while(m>0 && n>0){
            for(int k=0;k<n;k++){
                j+=dir;
                res.push_back(matrix[i][j]);
            }
            m--;
            for(int k=0;k<m;k++){
                i+=dir;
                res.push_back(matrix[i][j]);
            }
            n--;
            dir=-dir;
        }
        return res;
    }
};