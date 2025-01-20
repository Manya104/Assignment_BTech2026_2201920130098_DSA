class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int> mp;
        int m=mat.size();
        int n=mat[0].size();
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                mp[mat[i][j]] = i*n+j;
            }
        }
        unordered_map<int,int> rm,cm;
        for (int i=0;i<m*n;i++) {
            int row = mp[arr[i]] / n;
            int col = mp[arr[i]] % n;
            rm[row]++;
            cm[col]++;
            if (rm[row] == n || cm[col] == m) {
                return i;
            }
        }
        return -1;
    }
};