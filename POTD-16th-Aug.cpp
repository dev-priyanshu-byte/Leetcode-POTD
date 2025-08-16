class Solution {
public:
    int maximum69Number (int num) {
     int d=1,ans=0;
     while(d<num){
        if(num/d%10==6)
        ans=d;
        d*=10;
     }
     if(ans)
     num+=3*ans;
     return num;
    }
};
