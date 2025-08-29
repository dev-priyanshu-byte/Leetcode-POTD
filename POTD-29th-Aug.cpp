class Solution {
public:
    long long flowerGame(int n, int m) {
        long long res=0;
        for(int i=1;i<=n;i++)
        {
            if(i%2==0)
            {
                res+=ceil(1.0*m/2);
            }
            else
            {
                res+=m/2;
            }
            cout<<i<<" "<<res<<endl;
        }
        return res;
    }
};