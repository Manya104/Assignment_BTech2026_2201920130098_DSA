class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.length();

        queue<int> que;
        int a=0, b=0, c=0;
        int count = 0;
        
        for(int i=0; i<n;  i++){
            char ch = s[i];
            que.push(ch);
            if(ch=='a') a++;
            else if(ch=='b') b++;
            else if(ch=='c') c++;

            while(a>=1 && b>=1 && c>=1) {
                count += n-i;
                char frontChar = que.front();
                que.pop();
                if(frontChar=='a') a--;
                else if(frontChar=='b') b--;
                else if(frontChar=='c') c--;
            }
        }
        return count;
    }
};