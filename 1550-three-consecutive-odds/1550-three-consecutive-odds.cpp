class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i = 0;
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] % 2 == 0) {
                i = 0; // reset counter for even numbers
            } else {
                i++; // increment for odd numbers
            }
            if (i == 3) {
                return true; // found three consecutive odd numbers
            }
        }
        return false; // no such sequence found
    }
};
