class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>st;
        for(int n:nums){
           if( st.count(n)){
                return true;
            }
            st.insert(n);
        }
        return false;
    }
};