class Solution {
public:
    map<int,int> countDigits(int n){
        int d;
        map<int,int> mp;
        while(n>0)
        {
            d=n%10;
            mp[d]++;
            n/=10;
        }
        return mp;
    }
    bool compareDigits(map<int,int>&mp1,map<int,int>&mp2){
        int flag=1;

        for(int key=0;key<10;key++)
        {
            if(mp1[key]!=mp2[key])
            flag=0;
        }
        if(flag==0)
        return false;
        else
        return true;
    }
    bool reorderedPowerOf2(int n) {
        
        map<int,int>num;
        int pow=1;
        num=countDigits(n);
        for(int i=0;i<30;i++)
        {
            map<int,int> nums=countDigits(pow);
            if(compareDigits(nums,num))
            return true;
            pow=pow*2;
        }
        return false;
    }
};