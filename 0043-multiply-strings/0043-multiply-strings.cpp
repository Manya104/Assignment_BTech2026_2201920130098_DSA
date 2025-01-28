class Solution {
public:
string strsum(string str1,string str2)
{
    string result="";
    int n1=str1.size(),n2=str2.size();
    int i=n1-1,j=n2-1,carry=0;
    while(i>=0 && j>=0)
    {
        int sum=(str1[i]-'0')+(str2[j]-'0')+carry;
        carry=sum/10;
        sum%=10;
        result=to_string(sum)+result;
        i--;
        j--;
    }
    while(i>=0)
    {
        int sum=str1[i]-'0'+carry;
        carry=sum/10;
        result=to_string(sum%10)+result;
        i--;
    }
    while(j>=0)
    {
        int sum=+str2[j]-'0'+carry;
        carry=sum/10;
        result=to_string(sum%10)+result;
        j--;
    }
    while(carry)
    {
        result=to_string(carry)+result;
        carry/=10;
    }
    return result;
}
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
        return "0";
        string ans;
        int cnt=0;
        int n1=num1.size(),n2=num2.size();
        for(int i=n1-1;i>=0;i--)
        {
            int mul,carry=0;
            string res;
            for(int j=n2-1;j>=0;j--)
            { 
                mul=(num1[i]-'0')*(num2[j]-'0')+carry;
                carry=mul/10;
                mul=mul%10;
                res=to_string(mul)+res;
            }
            if(carry)
            res=to_string(carry)+res;
            for(int k=1;k<=cnt;k++)
            {
                res+="0";
            }
            ans=strsum(ans,res);
            cnt++;
        }
        return ans;
    }
};