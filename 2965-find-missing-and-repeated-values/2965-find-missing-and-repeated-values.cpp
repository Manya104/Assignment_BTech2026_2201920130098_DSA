class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        /**
           deciding a number place :
            int n = 7
            int num = 1-1 (num-1)
            int row = num/n -> 6/7 = 0
            int col = num%n -> 6%7 = 6
        **/
        int n = grid.size();
        int maxNum = n*n + 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int place = (grid[i][j])%maxNum - 1;

                int newRow = place/n;
                int newCol = place%n;

                grid[newRow][newCol] += maxNum;
            }
        }
        int missingNum = -1, repeatedNum = -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]/maxNum == 0)
                   missingNum = i*n + j + 1;
                else if(grid[i][j]/maxNum == 2)
                   repeatedNum = i*n + j + 1;
            }
        }
        return {repeatedNum, missingNum};
    }
};