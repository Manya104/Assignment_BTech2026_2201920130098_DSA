class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.size() < k){
            string str = s;
            for(int i=0; i<str.size(); i++){
                str[i] = str[i] + 1;
            }
            s = s + str;
        }
        return s[k-1];
    }
};