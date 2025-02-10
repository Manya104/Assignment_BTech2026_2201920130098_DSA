class Solution {
public:
    string clearDigits(string s) {
        int x=s.size();
        // a 2 b 3 c 4 d e 
        string res;
        for(char c:s){
            if(!isdigit(c)) res.push_back(c);
            else{
                if(!s.empty()) res.pop_back();
            }
        }
        return res;
    }
};