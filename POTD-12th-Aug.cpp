class Solution {
public:
    int sumWays(vector<int>&nums,int n){
        vector<vector<int>> sum(nums.size(),vector<int>(n+1,0));
        int mod=pow(10,9)+7;
        for(int i=0;i<sum.size();i++)
        sum[i][0]=1;
        sum[0][nums[0]]=1;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j<nums[i])
                sum[i][j]=sum[i-1][j];
                else
                sum[i][j]=(1ll*sum[i-1][j]+sum[i-1][j-nums[i]])%mod;
            }
        }
        return sum[nums.size()-1][n];
    }
    int numberOfWays(int n, int x) {
        vector<int> nums;
        for(int j=1;j<=300;j++)
        {
            if(pow(j,x)<=n)
            nums.push_back(pow(j,x));
        }
        return sumWays(nums,n);
    }
};