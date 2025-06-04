class Solution {
public:
    string answerString(string word, int numFriends) {
       int end=0,len=word.size()-(numFriends-1);
       if(numFriends==1)return word;
       vector<string>result;
       for(int i=0;i<word.size();i++){
        if(word[i]<end)continue;
        end=word[i];
        string t=word.substr(i,(word.size()-i)<len?word.size()-i:len);
        result.push_back(t);
       } 
       sort(result.begin(),result.end());
       return result.back();
    }
};