class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.length();
        while(i<n && s[i]==' '){
            i++;
        }
        int sign=1;
        if(i<n && s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(i<n && s[i]=='+'){
            i++;
        }
        long long num=0;
        long long limit=(sign==1)?INT_MAX:-(long long)INT_MIN;
        while(i<n && s[i]>='0' && s[i]<='9'){
            int digit=s[i]-'0';
        
        if(num>limit/10 || (num==limit/10 && digit>limit%10)){
            return (sign==1)?INT_MAX:INT_MIN;
        }
        num=num*10+digit;
        i++;
        }
        return (int)(num*sign);
        
    }
};