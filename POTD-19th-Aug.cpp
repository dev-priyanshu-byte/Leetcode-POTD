class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long z=0;
        int j;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)continue;
            else{
                j=i;
                while(j<nums.size()&&nums[i]==nums[j])j++;
                z+=1.0*(j-i)*(j-i+1)/2;
                i=j-1;
            }
        }
        return z;
    }
};