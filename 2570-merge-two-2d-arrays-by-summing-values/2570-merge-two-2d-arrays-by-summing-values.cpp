class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int> > ans;
        
        int idx1 = 0,idx2 = 0;
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        while(idx1 < sz1 && idx2 < sz2){
            int id1 = nums1[idx1][0];
            int id2 = nums2[idx2][0];
            vector<int> temp;
            if(id1==id2){
                temp.push_back(id2);
                temp.push_back(nums1[idx1][1]+nums2[idx2][1]);
                idx1++;idx2++;
            }
            else if(id1 > id2){
                temp.push_back(id2);
                temp.push_back(nums2[idx2][1]);
                idx2++;
            }else {
                temp.push_back(id1);
                temp.push_back(nums1[idx1][1]);
                idx1++;
            }
            ans.push_back(temp);
        }
        while(idx1 < sz1){
            ans.push_back(nums1[idx1++]);
        }
        while(idx2 < sz2){
            ans.push_back(nums2[idx2++]);
        }
        return ans;
    }
};