class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ans;
        map<int , int>mp;
        for(int i =0;i<digits.size();i++){
            mp[digits[i]]++;
        }
        for(int i =100;i<1000;i+=2){

            int num = i;
            int d1 = num/100;
            int d2 = (num / 10) % 10;
            int d3 = num%10;

            map<int, int> temp;
            temp[d1]++;
            temp[d2]++;
            temp[d3]++;

             bool canForm = true;
            for (auto [digit, count] : temp) {
                if (mp[digit] < count) {
                    canForm = false;
                    break;
                }
            }
            if(canForm){
                 ans.push_back(i);
            }
        }   

        return ans;
    }
};