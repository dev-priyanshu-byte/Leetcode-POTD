class Solution {
public:
    string largestGoodInteger(string num) {
        char ans='!';
        int j=0;
        for(int i=0;i<num.size();i++)
        {
            j=i;
            while(j<num.size()&&num[i]==num[j])j++;
            if(j-i>=3) ans=ans>num[i]?ans:num[i];
            i=j-1;
        }
        if(ans=='!')
        return "";
        string s="";
        s=s+ans+ans+ans;
        return s;
    }
};